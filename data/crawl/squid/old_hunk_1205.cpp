    buildTitleUrl();
    debugs(9, 5, HERE << "FD " << ctrl.conn->fd << " : host=" << request->GetHost() <<
           ", path=" << request->urlpath << ", user=" << user << ", passwd=" << password);

    state = BEGIN;
    ctrl.last_command = xstrdup("Connect to server");
    ctrl.buf = (char *)memAllocBuf(4096, &ctrl.size);
    ctrl.offset = 0;
    data.readBuf = new MemBuf;
    data.readBuf->init(4096, SQUID_TCP_SO_RCVBUF);
    scheduleReadControlReply(0);
}

/* ====================================================================== */

/// \ingroup ServerProtocolFTPInternal
static char *
escapeIAC(const char *buf)
{
    int n;
    char *ret;
    unsigned const char *p;
    unsigned char *r;

    for (p = (unsigned const char *)buf, n = 1; *p; ++n, ++p)
        if (*p == 255)
            ++n;

    ret = (char *)xmalloc(n);

    for (p = (unsigned const char *)buf, r=(unsigned char *)ret; *p; ++p) {
        *r = *p;
        ++r;

        if (*p == 255) {
            *r = 255;
            ++r;
        }
    }

    *r = '\0';
    ++r;
    assert((r - (unsigned char *)ret) == n );
    return ret;
}

void
FtpStateData::writeCommand(const char *buf)
{
    char *ebuf;
    /* trace FTP protocol communications at level 2 */
    debugs(9, 2, "ftp<< " << buf);

    if (Config.Ftp.telnet)
        ebuf = escapeIAC(buf);
    else
        ebuf = xstrdup(buf);

    safe_free(ctrl.last_command);

    safe_free(ctrl.last_reply);

    ctrl.last_command = ebuf;

    if (!Comm::IsConnOpen(ctrl.conn)) {
        debugs(9, 2, HERE << "cannot send to closing ctrl " << ctrl.conn);
        // TODO: assert(ctrl.closer != NULL);
        return;
    }

    typedef CommCbMemFunT<FtpStateData, CommIoCbParams> Dialer;
    AsyncCall::Pointer call = JobCallback(9, 5, Dialer, this, FtpStateData::ftpWriteCommandCallback);
    Comm::Write(ctrl.conn, ctrl.last_command, strlen(ctrl.last_command), call, NULL);

    scheduleReadControlReply(0);
}

void
FtpStateData::ftpWriteCommandCallback(const CommIoCbParams &io)
{

    debugs(9, 5, "ftpWriteCommandCallback: wrote " << io.size << " bytes");

    if (io.size > 0) {
        fd_bytes(io.fd, io.size, FD_WRITE);
        kb_incr(&(statCounter.server.all.kbytes_out), io.size);
        kb_incr(&(statCounter.server.ftp.kbytes_out), io.size);
    }

    if (io.flag == Comm::ERR_CLOSING)
        return;

    if (io.flag) {
        debugs(9, DBG_IMPORTANT, "ftpWriteCommandCallback: " << io.conn << ": " << xstrerr(io.xerrno));
        failed(ERR_WRITE_ERROR, io.xerrno);
        /* failed closes ctrl.conn and frees ftpState */
        return;
    }
}

wordlist *
FtpStateData::ftpParseControlReply(char *buf, size_t len, int *codep, size_t *used)
{
    char *s;
    char *sbuf;
    char *end;
    int usable;
    int complete = 0;
    wordlist *head = NULL;
    wordlist *list;
    wordlist **tail = &head;
    size_t offset;
    size_t linelen;
    int code = -1;
    debugs(9, 3, HERE);
    /*
     * We need a NULL-terminated buffer for scanning, ick
     */
    sbuf = (char *)xmalloc(len + 1);
    xstrncpy(sbuf, buf, len + 1);
    end = sbuf + len - 1;

    while (*end != '\r' && *end != '\n' && end > sbuf)
        --end;

    usable = end - sbuf;

    debugs(9, 3, HERE << "usable = " << usable);

    if (usable == 0) {
        debugs(9, 3, HERE << "didn't find end of line");
        safe_free(sbuf);
        return NULL;
    }

    debugs(9, 3, HERE << len << " bytes to play with");
    ++end;
    s = sbuf;
    s += strspn(s, crlf);

    for (; s < end; s += strcspn(s, crlf), s += strspn(s, crlf)) {
        if (complete)
            break;

        debugs(9, 5, HERE << "s = {" << s << "}");

        linelen = strcspn(s, crlf) + 1;

        if (linelen < 2)
            break;

        if (linelen > 3)
            complete = (*s >= '0' && *s <= '9' && *(s + 3) == ' ');

        if (complete)
            code = atoi(s);

        offset = 0;

        if (linelen > 3)
            if (*s >= '0' && *s <= '9' && (*(s + 3) == '-' || *(s + 3) == ' '))
                offset = 4;

        list = new wordlist();

        list->key = (char *)xmalloc(linelen - offset);

        xstrncpy(list->key, s + offset, linelen - offset);

        /* trace the FTP communication chat at level 2 */
        debugs(9, 2, "ftp>> " << code << " " << list->key);

        *tail = list;

        tail = &list->next;
    }

    *used = (size_t) (s - sbuf);
    safe_free(sbuf);

    if (!complete)
        wordlistDestroy(&head);

    if (codep)
        *codep = code;

    return head;
}

/**
 * DPW 2007-04-23
 * Looks like there are no longer anymore callers that set
 * buffered_ok=1.  Perhaps it can be removed at some point.
 */
void
FtpStateData::scheduleReadControlReply(int buffered_ok)
{
    debugs(9, 3, HERE << ctrl.conn);

    if (buffered_ok && ctrl.offset > 0) {
        /* We've already read some reply data */
        handleControlReply();
    } else {
        /*
         * Cancel the timeout on the Data socket (if any) and
         * establish one on the control socket.
         */
        if (Comm::IsConnOpen(data.conn)) {
            commUnsetConnTimeout(data.conn);
        }

        typedef CommCbMemFunT<FtpStateData, CommTimeoutCbParams> TimeoutDialer;
        AsyncCall::Pointer timeoutCall = JobCallback(9, 5, TimeoutDialer, this, FtpStateData::ftpTimeout);
        commSetConnTimeout(ctrl.conn, Config.Timeout.read, timeoutCall);

        typedef CommCbMemFunT<FtpStateData, CommIoCbParams> Dialer;
        AsyncCall::Pointer reader = JobCallback(9, 5, Dialer, this, FtpStateData::ftpReadControlReply);
        comm_read(ctrl.conn, ctrl.buf + ctrl.offset, ctrl.size - ctrl.offset, reader);
    }
}

void FtpStateData::ftpReadControlReply(const CommIoCbParams &io)
{
    debugs(9, 3, "ftpReadControlReply: FD " << io.fd << ", Read " << io.size << " bytes");

    if (io.size > 0) {
        kb_incr(&(statCounter.server.all.kbytes_in), io.size);
        kb_incr(&(statCounter.server.ftp.kbytes_in), io.size);
    }

    if (io.flag == Comm::ERR_CLOSING)
        return;

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        abortTransaction("entry aborted during control reply read");
        return;
    }

    assert(ctrl.offset < ctrl.size);

    if (io.flag == Comm::OK && io.size > 0) {
        fd_bytes(io.fd, io.size, FD_READ);
    }

    if (io.flag != Comm::OK) {
        debugs(50, ignoreErrno(io.xerrno) ? 3 : DBG_IMPORTANT,
               "ftpReadControlReply: read error: " << xstrerr(io.xerrno));

        if (ignoreErrno(io.xerrno)) {
            scheduleReadControlReply(0);
        } else {
            failed(ERR_READ_ERROR, io.xerrno);
            /* failed closes ctrl.conn and frees ftpState */
        }
        return;
    }

    if (io.size == 0) {
        if (entry->store_status == STORE_PENDING) {
            failed(ERR_FTP_FAILURE, 0);
            /* failed closes ctrl.conn and frees ftpState */
            return;
        }

        /* XXX this may end up having to be serverComplete() .. */
        abortTransaction("zero control reply read");
        return;
    }

    unsigned int len =io.size + ctrl.offset;
    ctrl.offset = len;
    assert(len <= ctrl.size);
    handleControlReply();
}

void
FtpStateData::handleControlReply()
{
    wordlist **W;
    size_t bytes_used = 0;
    wordlistDestroy(&ctrl.message);
    ctrl.message = ftpParseControlReply(ctrl.buf,
                                        ctrl.offset, &ctrl.replycode, &bytes_used);

    if (ctrl.message == NULL) {
        /* didn't get complete reply yet */

        if (ctrl.offset == ctrl.size) {
            ctrl.buf = (char *)memReallocBuf(ctrl.buf, ctrl.size << 1, &ctrl.size);
        }

        scheduleReadControlReply(0);
        return;
    } else if (ctrl.offset == bytes_used) {
        /* used it all up */
        ctrl.offset = 0;
    } else {
        /* Got some data past the complete reply */
        assert(bytes_used < ctrl.offset);
        ctrl.offset -= bytes_used;
        memmove(ctrl.buf, ctrl.buf + bytes_used, ctrl.offset);
    }

    /* Move the last line of the reply message to ctrl.last_reply */
    for (W = &ctrl.message; (*W)->next; W = &(*W)->next);
    safe_free(ctrl.last_reply);

    ctrl.last_reply = xstrdup((*W)->key);

    wordlistDestroy(W);

    /* Copy the rest of the message to cwd_message to be printed in
     * error messages
     */
    if (ctrl.message) {
        for (wordlist *w = ctrl.message; w; w = w->next) {
            cwd_message.append('\n');
            cwd_message.append(w->key);
        }
    }

    debugs(9, 3, HERE << "state=" << state << ", code=" << ctrl.replycode);

    FTP_SM_FUNCS[state] (this);
}

/* ====================================================================== */

/// \ingroup ServerProtocolFTPInternal
static void
ftpReadWelcome(FtpStateData * ftpState)
{
    int code = ftpState->ctrl.replycode;
    debugs(9, 3, HERE);
