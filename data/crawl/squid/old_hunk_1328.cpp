    /* NOTE: pinning.pinned should be kept. This combined with fd == -1 at the end of a request indicates that the host
     * connection has gone away */
}

const char *
ConnStateData::ftpBuildUri(const char *file)
{
    ftp.uri = "ftp://";
    ftp.uri.append(ftp.host);
    if (port->ftp_track_dirs && ftp.workingDir.size()) {
        if (ftp.workingDir[0] != '/')
            ftp.uri.append("/");
        ftp.uri.append(ftp.workingDir);
    }

    if (ftp.uri[ftp.uri.size() - 1] != '/')
        ftp.uri.append("/");

    if (port->ftp_track_dirs && file) {
        //remove any '/' from the beginning of path
        while (*file == '/')
            ++file;
        ftp.uri.append(file);
    }

    return ftp.uri.termedBuf();
}

void
ConnStateData::ftpSetWorkingDir(const char *dir)
{
    ftp.workingDir = dir;
}

static void
FtpAcceptDataConnection(const CommAcceptCbParams &params)
{
    ConnStateData *connState = static_cast<ConnStateData *>(params.data);

    if (params.flag != Comm::OK) {
        // Its possible the call was still queued when the client disconnected
        debugs(33, 2, HERE << connState->ftp.dataListenConn << ": accept "
               "failure: " << xstrerr(params.xerrno));
        return;
    }

    debugs(33, 4, "accepted " << params.conn);
    fd_note(params.conn->fd, "passive client ftp data");
    ++incoming_sockets_accepted;

    if (!connState->clientConnection) {
        debugs(33, 5, "late data connection?");
        FtpCloseDataConnection(connState); // in case we are still listening
        params.conn->close();
    } else
    if (params.conn->remote != connState->clientConnection->remote) {
        debugs(33, 2, "rogue data conn? ctrl: " << connState->clientConnection->remote);
        params.conn->close();
        // Some FTP servers close control connection here, but it may make
        // things worse from DoS p.o.v. and no better from data stealing p.o.v.
    } else {
        FtpCloseDataConnection(connState);
        connState->ftp.dataConn = params.conn;
        connState->ftp.uploadAvailSize = 0;
        debugs(33, 7, "ready for data");
        if (connState->ftp.onDataAcceptCall != NULL) {
            AsyncCall::Pointer call = connState->ftp.onDataAcceptCall;
            connState->ftp.onDataAcceptCall = NULL;
            // If we got an upload request, start reading data from the client.
            if (connState->ftp.state == ConnStateData::FTP_HANDLE_UPLOAD_REQUEST)
                connState->readSomeFtpData();
            else
                Must(connState->ftp.state == ConnStateData::FTP_HANDLE_DATA_REQUEST);
            MemBuf mb;
            mb.init();
            mb.Printf("150 Data connection opened.\r\n");
            Comm::Write(connState->clientConnection, &mb, call);
        }
    }
}

static void
FtpCloseDataConnection(ConnStateData *conn)
{
    if (conn->ftp.listener != NULL) {
        conn->ftp.listener->cancel("no longer needed");
        conn->ftp.listener = NULL;
    }

    if (Comm::IsConnOpen(conn->ftp.dataListenConn)) {
        debugs(33, 5, HERE << "FTP closing client data listen socket: " <<
               *conn->ftp.dataListenConn);
        conn->ftp.dataListenConn->close();
    }
    conn->ftp.dataListenConn = NULL;

    if (conn->ftp.reader != NULL) {
        // Comm::ReadCancel can deal with negative FDs
        Comm::ReadCancel(conn->ftp.dataConn->fd, conn->ftp.reader);
        conn->ftp.reader = NULL;
    }

    if (Comm::IsConnOpen(conn->ftp.dataConn)) {
        debugs(33, 5, HERE << "FTP closing client data connection: " <<
               *conn->ftp.dataConn);
        conn->ftp.dataConn->close();
    }
    conn->ftp.dataConn = NULL;
}

/// Writes FTP [error] response before we fully parsed the FTP request and
/// created the corresponding HTTP request wrapper for that FTP request.
static void
FtpWriteEarlyReply(ConnStateData *connState, const int code, const char *msg)
{
    debugs(33, 7, HERE << code << ' ' << msg);
    assert(99 < code && code < 1000);

    MemBuf mb;
    mb.init();
    mb.Printf("%i %s\r\n", code, msg);

    AsyncCall::Pointer call = commCbCall(33, 5, "FtpWroteEarlyReply",
        CommIoCbPtrFun(&FtpWroteEarlyReply, connState));
    Comm::Write(connState->clientConnection, &mb, call);

    connState->flags.readMore = false;

    // TODO: Create master transaction. Log it in FtpWroteEarlyReply.
}

static void
FtpWriteReply(ClientSocketContext *context, MemBuf &mb)
{
    debugs(11, 2, "FTP Client " << context->clientConnection);
    debugs(11, 2, "FTP Client REPLY:\n---------\n" << mb.buf <<
           "\n----------");

    AsyncCall::Pointer call = commCbCall(33, 5, "FtpWroteReply",
        CommIoCbPtrFun(&FtpWroteReply, context));
    Comm::Write(context->clientConnection, &mb, call);
}

static void
FtpWriteCustomReply(ClientSocketContext *context, const int code, const char *msg, const HttpReply *reply)
{
    debugs(33, 7, HERE << code << ' ' << msg);
    assert(99 < code && code < 1000);

    const bool sendDetails = reply != NULL &&
        reply->header.has(HDR_FTP_STATUS) && reply->header.has(HDR_FTP_REASON);

    MemBuf mb;
    mb.init();
    if (sendDetails) {
        mb.Printf("%i-%s\r\n", code, msg);
        mb.Printf(" Server reply:\r\n");
        FtpPrintReply(mb, reply, " ");
        mb.Printf("%i \r\n", code);
    } else
        mb.Printf("%i %s\r\n", code, msg);

    FtpWriteReply(context, mb);
}

static void 
FtpChangeState(ConnStateData *connState, const ConnStateData::FtpState newState, const char *reason)
{
    assert(connState);
    if (connState->ftp.state == newState) {
        debugs(33, 3, "client state unchanged at " << connState->ftp.state <<
               " because " << reason);
        connState->ftp.state = newState;
    } else {
        debugs(33, 3, "client state was " << connState->ftp.state <<
               ", now " << newState << " because " << reason);
        connState->ftp.state = newState;
    }
}

/** Parse an FTP request
 *
 *  \note Sets result->flags.parsed_ok to 0 if failed to parse the request,
 *          to 1 if the request was correctly parsed.
 *  \param[in] connState a ConnStateData. The caller must make sure it is not null
 *  \param[out] mehtod_p will be set as a side-effect of the parsing.
 *          Pointed-to value will be set to Http::METHOD_NONE in case of
 *          parsing failure
 *  \param[out] http_ver will be set as a side-effect of the parsing
 *  \return NULL on incomplete requests,
 *          a ClientSocketContext structure on success or failure.
 */
static ClientSocketContext *
FtpParseRequest(ConnStateData *connState, HttpRequestMethod *method_p, Http::ProtocolVersion *http_ver)
{
    *http_ver = Http::ProtocolVersion(1, 1);

    // TODO: Use tokenizer for parsing instead of raw pointer manipulation.
    const char *inBuf = connState->in.buf.rawContent();

    const char *const eor =
        static_cast<const char *>(memchr(inBuf, '\n',
            min(static_cast<size_t>(connState->in.buf.length()), Config.maxRequestHeaderSize)));

    if (eor == NULL && connState->in.buf.length() >= Config.maxRequestHeaderSize) {
        FtpChangeState(connState, ConnStateData::FTP_ERROR, "huge req");
        FtpWriteEarlyReply(connState, 421, "Too large request");
        return NULL;
    }

    if (eor == NULL) {
        debugs(33, 5, HERE << "Incomplete request, waiting for end of request");
        return NULL;
    }

    const size_t req_sz = eor + 1 - inBuf;

    // skip leading whitespaces
    const char *boc = inBuf; // beginning of command
    while (boc < eor && isspace(*boc)) ++boc;
    if (boc >= eor) {
        debugs(33, 5, HERE << "Empty request, ignoring");
        connNoteUseOfBuffer(connState, req_sz);
        return NULL;
    }

    const char *eoc = boc; // end of command
    while (eoc < eor && !isspace(*eoc)) ++eoc;
    connState->in.buf.setAt(eoc - inBuf, '\0');

    const char *bop = eoc + 1; // beginning of parameter
    while (bop < eor && isspace(*bop)) ++bop;
    if (bop < eor) {
        const char *eop = eor - 1;
        while (isspace(*eop)) --eop;
        assert(eop >= bop);
        connState->in.buf.setAt(eop + 1 - inBuf, '\0');
    } else
        bop = NULL;

    debugs(33, 7, HERE << "Parsed FTP command " << boc << " with " <<
           (bop == NULL ? "no " : "") << "parameters" <<
           (bop != NULL ? ": " : "") << bop);

    // TODO: Use SBuf instead of String
    const String cmd = boc;
    String params = bop;

    connNoteUseOfBuffer(connState, req_sz);

    if (!connState->ftp.readGreeting) {
        // the first command must be USER
        if (!connState->pinning.pinned && cmd.caseCmp("USER") != 0) {
            FtpWriteEarlyReply(connState, 530, "Must login first");
            return NULL;
        }
    }

    // We need to process USER request now because it sets ftp server Hostname.
    if (cmd.caseCmp("USER") == 0 &&
        !FtpHandleUserRequest(connState, cmd, params))
        return NULL;

    if (!FtpSupportedCommand(cmd)) {
        FtpWriteEarlyReply(connState, 502, "Unknown or unsupported command");
        return NULL;
    }

    *method_p = !cmd.caseCmp("APPE") || !cmd.caseCmp("STOR") ||
        !cmd.caseCmp("STOU") ? Http::METHOD_PUT : Http::METHOD_GET;

    char *uri;
    const char *aPath = params.size() > 0 && Ftp::hasPathParameter(cmd)?
        params.termedBuf() : NULL;
    uri = xstrdup(connState->ftpBuildUri(aPath));
    HttpRequest *const request =
        HttpRequest::CreateFromUrlAndMethod(uri, *method_p);
    if (request == NULL) {
        debugs(33, 5, HERE << "Invalid FTP URL: " << connState->ftp.uri);
        FtpWriteEarlyReply(connState, 501, "Invalid host");
        connState->ftp.uri.clean();
        safe_free(uri);
        return NULL;
    }

    request->http_ver = *http_ver;

    // Our fake Request-URIs are not distinctive enough for caching to work
    request->flags.cachable = false; // XXX: reset later by maybeCacheable()
    request->flags.noCache = true;

    request->header.putStr(HDR_FTP_COMMAND, cmd.termedBuf());
    request->header.putStr(HDR_FTP_ARGUMENTS, params.termedBuf() != NULL ?
                           params.termedBuf() : "");
    if (*method_p == Http::METHOD_PUT) {
        request->header.putStr(HDR_EXPECT, "100-continue");
        request->header.putStr(HDR_TRANSFER_ENCODING, "chunked");
    }

    ClientHttpRequest *const http = new ClientHttpRequest(connState);
    http->request = request;
    HTTPMSGLOCK(http->request);
    http->req_sz = req_sz;
    http->uri = uri;

    ClientSocketContext *const result =
        new ClientSocketContext(connState->clientConnection, http);

    StoreIOBuffer tempBuffer;
    tempBuffer.data = result->reqbuf;
    tempBuffer.length = HTTP_REQBUF_SZ;

    ClientStreamData newServer = new clientReplyContext(http);
    ClientStreamData newClient = result;
    clientStreamInit(&http->client_stream, clientGetMoreData, clientReplyDetach,
                     clientReplyStatus, newServer, clientSocketRecipient,
                     clientSocketDetach, newClient, tempBuffer);

    result->registerWithConn();
    result->flags.parsed_ok = 1;
    connState->flags.readMore = false;
    return result;
}

static void
FtpHandleReply(ClientSocketContext *context, HttpReply *reply, StoreIOBuffer data)
{
    if (context->http && context->http->al != NULL &&
        !context->http->al->reply && reply) {
        context->http->al->reply = reply;
        HTTPMSGLOCK(context->http->al->reply);
    }

    static FtpReplyHandler *handlers[] = {
        NULL, // FTP_BEGIN
        NULL, // FTP_CONNECTED
        FtpHandleFeatReply, // FTP_HANDLE_FEAT
        FtpHandlePasvReply, // FTP_HANDLE_PASV
        FtpHandlePortReply, // FTP_HANDLE_PORT
        FtpHandleDataReply, // FTP_HANDLE_DATA_REQUEST
        FtpHandleUploadReply, // FTP_HANDLE_UPLOAD_REQUEST
        FtpHandleEprtReply,// FTP_HANDLE_EPRT
        FtpHandleEpsvReply,// FTP_HANDLE_EPSV
        NULL, // FTP_HANDLE_CWD
        NULL, //FTP_HANDLE_PASS
        NULL, // FTP_HANDLE_CDUP
        FtpHandleErrorReply // FTP_ERROR
    };
    const ConnStateData::FtpState state = context->getConn()->ftp.state;
    FtpReplyHandler *const handler = handlers[state];
    if (handler)
        (*handler)(context, reply, data);
    else
        FtpWriteForwardedReply(context, reply);
}

static void
FtpHandleFeatReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
{
    if (context->http->request->errType != ERR_NONE) {
        FtpWriteCustomReply(context, 502, "Server does not support FEAT", reply);
        return;
    }

    HttpReply *filteredReply = reply->clone();
    HttpHeader &filteredHeader = filteredReply->header;

    // Remove all unsupported commands from the response wrapper.
    int deletedCount = 0;
    HttpHeaderPos pos = HttpHeaderInitPos;
    bool hasEPRT = false;
    bool hasEPSV = false;
    int prependSpaces = 1;
    while (const HttpHeaderEntry *e = filteredHeader.getEntry(&pos)) {
        if (e->id == HDR_FTP_PRE) {
            // assume RFC 2389 FEAT response format, quoted by Squid:
            // <"> SP NAME [SP PARAMS] <">
            // but accommodate MS servers sending four SPs before NAME
            if (e->value.size() < 4)
                continue;
            const char *raw = e->value.termedBuf();
            if (raw[0] != '"' || raw[1] != ' ')
                continue;
            const char *beg = raw + 1 + strspn(raw + 1, " "); // after quote and spaces
            // command name ends with (SP parameter) or quote
            const char *end = beg + strcspn(beg, " \"");

            if (end <= beg)
                continue;

            // compute the number of spaces before the command
            prependSpaces = beg - raw - 1;

            const String cmd = e->value.substr(beg-raw, end-raw);

            if (!FtpSupportedCommand(cmd))
                filteredHeader.delAt(pos, deletedCount);

            if (cmd == "EPRT")
                hasEPRT = true;
            else if (cmd == "EPSV")
                hasEPSV = true;
        }
    }

    char buf[256];
    int insertedCount = 0;
    if (!hasEPRT) {
        snprintf(buf, sizeof(buf), "\"%*s\"", prependSpaces + 4, "EPRT");
        filteredHeader.putStr(HDR_FTP_PRE, buf);
        ++insertedCount;
    }
    if (!hasEPSV) {
        snprintf(buf, sizeof(buf), "\"%*s\"", prependSpaces + 4, "EPSV");
        filteredHeader.putStr(HDR_FTP_PRE, buf);
        ++insertedCount;
    }

    if (deletedCount || insertedCount) {
        filteredHeader.refreshMask();
        debugs(33, 5, "deleted " << deletedCount << " inserted " << insertedCount);
    }

    FtpWriteForwardedReply(context, filteredReply);
}

static void
FtpHandlePasvReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
{
    if (context->http->request->errType != ERR_NONE) {
        FtpWriteCustomReply(context, 502, "Server does not support PASV", reply);
        return;
    }

    FtpCloseDataConnection(context->getConn());

    Comm::ConnectionPointer conn = new Comm::Connection;
    ConnStateData * const connState = context->getConn();
    conn->flags = COMM_NONBLOCKING;
    conn->local = connState->transparent() ?
                  connState->port->s : context->clientConnection->local;
    conn->local.port(0);
    const char *const note = connState->ftp.uri.termedBuf();
    comm_open_listener(SOCK_STREAM, IPPROTO_TCP, conn, note);
    if (!Comm::IsConnOpen(conn)) {
            debugs(5, DBG_CRITICAL, HERE << "comm_open_listener failed:" <<
                   conn->local << " error: " << errno);
            FtpWriteCustomReply(context, 451, "Internal error");
            return;
    }

    typedef CommCbFunPtrCallT<CommAcceptCbPtrFun> AcceptCall;
    RefCount<AcceptCall> subCall = commCbCall(5, 5, "FtpAcceptDataConnection",
        CommAcceptCbPtrFun(FtpAcceptDataConnection, connState));
    Subscription::Pointer sub = new CallSubscription<AcceptCall>(subCall);
    connState->ftp.listener = subCall.getRaw();
    connState->ftp.dataListenConn = conn;
    AsyncJob::Start(new Comm::TcpAcceptor(conn, note, sub));

    char addr[MAX_IPSTRLEN];
    // remote server in interception setups and local address otherwise
    const Ip::Address &server = connState->transparent() ?
                                context->clientConnection->local : conn->local;
    server.toStr(addr, MAX_IPSTRLEN, AF_INET);
    addr[MAX_IPSTRLEN - 1] = '\0';
    for (char *c = addr; *c != '\0'; ++c) {
        if (*c == '.')
            *c = ',';
    }

    // conn->fd is the client data connection (and its local port)
    const unsigned short port = comm_local_port(conn->fd);
    conn->local.port(port);

    // In interception setups, we combine remote server address with a
    // local port number and hope that traffic will be redirected to us.
    MemBuf mb;
    mb.init();

    // Do not use "227 =a,b,c,d,p1,p2" format or omit parens: some nf_ct_ftp
    // versions block responses that use those alternative syntax rules!
    mb.Printf("227 Entering Passive Mode (%s,%i,%i).\r\n",
              addr,
              static_cast<int>(port / 256),
              static_cast<int>(port % 256));

    debugs(11, 3, Raw("writing", mb.buf, mb.size));
    FtpWriteReply(context, mb);
}

static void
FtpHandlePortReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
{
    if (context->http->request->errType != ERR_NONE) {
        FtpWriteCustomReply(context, 502, "Server does not support PASV (converted from PORT)", reply);
        return;
    }

    FtpWriteCustomReply(context, 200, "PORT successfully converted to PASV.");

    // and wait for RETR
}

static void
FtpHandleErrorReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
{
    ConnStateData *const connState = context->getConn();
    if (!connState->pinning.pinned) // we failed to connect to server
        connState->ftp.uri.clean();
    // 421: we will close due to FTP_ERROR
    FtpWriteErrorReply(context, reply, 421);
}

static void
FtpHandleDataReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
{
    ConnStateData *const conn = context->getConn();

    if (reply != NULL && reply->sline.status() != Http::scOkay) {
        FtpWriteForwardedReply(context, reply);
        if (conn && Comm::IsConnOpen(conn->ftp.dataConn)) {
            debugs(33, 3, "closing " << conn->ftp.dataConn << " on KO reply");
            FtpCloseDataConnection(conn);
        }
        return;
    }

    if (!conn->ftp.dataConn) {
        // We got STREAM_COMPLETE (or error) and closed the client data conn.
        debugs(33, 3, "ignoring FTP srv data response after clt data closure");
        return;
    }

    if (!FtpCheckDataConnPost(context)) {
        FtpWriteCustomReply(context, 425, "Data connection is not established.");
        FtpCloseDataConnection(conn);
        return;
    }

    debugs(33, 7, HERE << data.length);

    if (data.length <= 0) {
        FtpWroteReplyData(conn->clientConnection, NULL, 0, Comm::OK, 0, context);
        return;
    }

    MemBuf mb;
    mb.init(data.length + 1, data.length + 1);
    mb.append(data.data, data.length);

    AsyncCall::Pointer call = commCbCall(33, 5, "FtpWroteReplyData",
        CommIoCbPtrFun(&FtpWroteReplyData, context));
    Comm::Write(conn->ftp.dataConn, &mb, call);

    context->noteSentBodyBytes(data.length);
}

static void
FtpWroteReplyData(const Comm::ConnectionPointer &conn, char *bufnotused, size_t size, Comm::Flag errflag, int xerrno, void *data)
{
    if (errflag == Comm::ERR_CLOSING)
        return;

    ClientSocketContext *const context = static_cast<ClientSocketContext*>(data);
    ConnStateData *const connState = context->getConn();

    if (errflag != Comm::OK) {
        debugs(33, 3, HERE << "FTP reply data writing failed: " <<
               xstrerr(xerrno));
        FtpCloseDataConnection(connState);
        FtpWriteCustomReply(context, 426, "Data connection error; transfer aborted");
        return;
    }

    assert(context->http);
    context->http->out.size += size;

    switch (context->socketState()) {
    case STREAM_NONE:
        debugs(33, 3, "Keep going");
        context->pullData();
        return;
    case STREAM_COMPLETE:
        debugs(33, 3, HERE << "FTP reply data transfer successfully complete");
        FtpWriteCustomReply(context, 226, "Transfer complete");
        break;
    case STREAM_UNPLANNED_COMPLETE:
        debugs(33, 3, HERE << "FTP reply data transfer failed: STREAM_UNPLANNED_COMPLETE");
        FtpWriteCustomReply(context, 451, "Server error; transfer aborted");
        break;
    case STREAM_FAILED:
        debugs(33, 3, HERE << "FTP reply data transfer failed: STREAM_FAILED");
        FtpWriteCustomReply(context, 451, "Server error; transfer aborted");
        break;
    default:
        fatal("unreachable code");
    }

    FtpCloseDataConnection(connState);
}

static void
FtpHandleUploadReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
{
    FtpWriteForwardedReply(context, reply);
    // note that the client data connection may already be closed by now
}

static void
FtpWriteForwardedReply(ClientSocketContext *context, const HttpReply *reply)
{
    const AsyncCall::Pointer call = commCbCall(33, 5, "FtpWroteReply",
        CommIoCbPtrFun(&FtpWroteReply, context));
    FtpWriteForwardedReply(context, reply, call);
}

static void
FtpHandleEprtReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
{
    if (context->http->request->errType != ERR_NONE) {
        FtpWriteCustomReply(context, 502, "Server does not support PASV (converted from EPRT)", reply);
        return;
    }

    FtpWriteCustomReply(context, 200, "EPRT successfully converted to PASV.");

    // and wait for RETR
}

static void
FtpHandleEpsvReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
{
    if (context->http->request->errType != ERR_NONE) {
        FtpWriteCustomReply(context, 502, "Cannot connect to server", reply);
        return;
    }

    FtpCloseDataConnection(context->getConn());

    Comm::ConnectionPointer conn = new Comm::Connection;
    ConnStateData * const connState = context->getConn();
    conn->flags = COMM_NONBLOCKING;
    conn->local = connState->transparent() ?
                  connState->port->s : context->clientConnection->local;
    conn->local.port(0);
    const char *const note = connState->ftp.uri.termedBuf();
    comm_open_listener(SOCK_STREAM, IPPROTO_TCP, conn, note);
    if (!Comm::IsConnOpen(conn)) {
            debugs(5, DBG_CRITICAL, "comm_open_listener failed: " <<
                   conn->local << " error: " << errno);
            FtpWriteCustomReply(context, 451, "Internal error");
            return;
    }

    typedef CommCbFunPtrCallT<CommAcceptCbPtrFun> AcceptCall;
    RefCount<AcceptCall> subCall = commCbCall(5, 5, "FtpAcceptDataConnection",
        CommAcceptCbPtrFun(FtpAcceptDataConnection, connState));
    Subscription::Pointer sub = new CallSubscription<AcceptCall>(subCall);
    connState->ftp.listener = subCall.getRaw();
    connState->ftp.dataListenConn = conn;
    AsyncJob::Start(new Comm::TcpAcceptor(conn, note, sub));

    // conn->fd is the client data connection (and its local port)
    const unsigned int port = comm_local_port(conn->fd);
    conn->local.port(port);

    // In interception setups, we combine remote server address with a
    // local port number and hope that traffic will be redirected to us.
    MemBuf mb;
    mb.init();
    mb.Printf("229 Entering Extended Passive Mode (|||%u|)\r\n", port);

    debugs(11, 3, Raw("writing", mb.buf, mb.size));
    FtpWriteReply(context, mb);
}

/// writes FTP error response with given status and reply-derived error details
static void
FtpWriteErrorReply(ClientSocketContext *context, const HttpReply *reply, const int status)
{
    MemBuf mb;
    mb.init();

    assert(context->http);
    const HttpRequest *request = context->http->request;
    assert(request);
    if (request->errType != ERR_NONE)
        mb.Printf("%i-%s\r\n", status, errorPageName(request->errType));

    if (request->errDetail > 0) {
        // XXX: > 0 may not always mean that this is an errno
        mb.Printf("%i-Error: (%d) %s\r\n", status,
                  request->errDetail,
                  strerror(request->errDetail));
    }

    // XXX: Remove hard coded names. Use an error page template instead.
    const Adaptation::History::Pointer ah = request->adaptHistory();
    if (ah != NULL) { // XXX: add adapt::<all_h but use lastMeta here
        const String info = ah->allMeta.getByName("X-Response-Info");
        const String desc = ah->allMeta.getByName("X-Response-Desc");
        if (info.size())
            mb.Printf("%i-Information: %s\r\n", status, info.termedBuf());
        if (desc.size())
            mb.Printf("%i-Description: %s\r\n", status, desc.termedBuf());
    }

    assert(reply != NULL);
    const char *reason = reply->header.has(HDR_FTP_REASON) ?
                         reply->header.getStr(HDR_FTP_REASON):
                         reply->sline.reason();

    mb.Printf("%i %s\r\n", status, reason); // error terminating line

    // TODO: errorpage.cc should detect FTP client and use
    // configurable FTP-friendly error templates which we should
    // write to the client "as is" instead of hiding most of the info

    FtpWriteReply(context, mb);
}

/// writes FTP response based on HTTP reply that is not an FTP-response wrapper
static void 
FtpWriteForwardedForeign(ClientSocketContext *context, const HttpReply *reply)
{
    ConnStateData *const connState = context->getConn();
    FtpChangeState(connState, ConnStateData::FTP_CONNECTED, "foreign reply");
    //Close the data connection.
    FtpCloseDataConnection(connState);
    // 451: We intend to keep the control connection open.
    FtpWriteErrorReply(context, reply, 451);
}

static void
FtpWriteForwardedReply(ClientSocketContext *context, const HttpReply *reply, AsyncCall::Pointer call)
{
    assert(reply != NULL);
    const HttpHeader &header = reply->header;
    ConnStateData *const connState = context->getConn();

    // adaptation and forwarding errors lack HDR_FTP_STATUS
    if (!header.has(HDR_FTP_STATUS)) {
        FtpWriteForwardedForeign(context, reply);
        return;
    }

    assert(header.has(HDR_FTP_REASON));

    const int status = header.getInt(HDR_FTP_STATUS);
    debugs(33, 7, HERE << "status: " << status);

    // Status 125 or 150 implies upload or data request, but we still check
    // the state in case the server is buggy.
    if ((status == 125 || status == 150) &&
        (connState->ftp.state == ConnStateData::FTP_HANDLE_UPLOAD_REQUEST ||
         connState->ftp.state == ConnStateData::FTP_HANDLE_DATA_REQUEST)) {
        if (FtpCheckDataConnPost(context)) {
            // If the data connection is ready, start reading data (here)
            // and forward the response to client (further below).
            debugs(33, 7, "data connection established, start data transfer");
            if (connState->ftp.state == ConnStateData::FTP_HANDLE_UPLOAD_REQUEST)
                connState->readSomeFtpData();
        } else {
            // If we are waiting to accept the data connection, keep waiting.
            if (Comm::IsConnOpen(connState->ftp.dataListenConn)) {
                debugs(33, 7, "wait for the client to establish a data connection");
                connState->ftp.onDataAcceptCall = call;
                // TODO: Add connect timeout for passive connections listener?
                // TODO: Remember server response so that we can forward it?
            } else {
                // Either the connection was establised and closed after the
                // data was transferred OR we failed to establish an active
                // data connection and already sent the error to the client.
                // In either case, there is nothing more to do.
                debugs(33, 7, "done with data OR active connection failed");
            }
            return;
        }
    }

    MemBuf mb;
    mb.init();
    FtpPrintReply(mb, reply);

    debugs(11, 2, "FTP Client " << context->clientConnection);
    debugs(11, 2, "FTP Client REPLY:\n---------\n" << mb.buf <<
           "\n----------");

    Comm::Write(context->clientConnection, &mb, call);
}

static void
FtpPrintReply(MemBuf &mb, const HttpReply *reply, const char *const prefix)
{
    const HttpHeader &header = reply->header;

    HttpHeaderPos pos = HttpHeaderInitPos;
    while (const HttpHeaderEntry *e = header.getEntry(&pos)) {
        if (e->id == HDR_FTP_PRE) {
            String raw;
            if (httpHeaderParseQuotedString(e->value.rawBuf(), e->value.size(), &raw))
                mb.Printf("%s\r\n", raw.termedBuf());
        }
    }

    if (header.has(HDR_FTP_STATUS)) {
        const char *reason = header.getStr(HDR_FTP_REASON);
        mb.Printf("%i %s\r\n", header.getInt(HDR_FTP_STATUS),
                  (reason ? reason : 0));
    }
}

static void
FtpWroteEarlyReply(const Comm::ConnectionPointer &conn, char *bufnotused, size_t size, Comm::Flag errflag, int xerrno, void *data)
{
    if (errflag == Comm::ERR_CLOSING)
        return;

    if (errflag != Comm::OK) {
        debugs(33, 3, HERE << "FTP reply writing failed: " << xstrerr(xerrno));
        conn->close();
        return;
    }

    ConnStateData *const connState = static_cast<ConnStateData*>(data);
    ClientSocketContext::Pointer context = connState->getCurrentContext();
    if (context != NULL && context->http) {
        context->http->out.size += size;
        context->http->out.headers_sz += size;
    }

    connState->flags.readMore = true;
    connState->readSomeData();
}

static void
FtpWroteReply(const Comm::ConnectionPointer &conn, char *bufnotused, size_t size, Comm::Flag errflag, int xerrno, void *data)
{
    if (errflag == Comm::ERR_CLOSING)
        return;

    if (errflag != Comm::OK) {
        debugs(33, 3, HERE << "FTP reply writing failed: " <<
               xstrerr(xerrno));
        conn->close();
        return;
    }

    ClientSocketContext *const context =
        static_cast<ClientSocketContext*>(data);
    ConnStateData *const connState = context->getConn();

    assert(context->http);
    context->http->out.size += size;
    context->http->out.headers_sz += size;

    if (connState->ftp.state == ConnStateData::FTP_ERROR) {
        debugs(33, 5, "closing on FTP server error");
        conn->close();
        return;
    }

    const clientStream_status_t socketState = context->socketState();
    debugs(33, 5, "FTP client stream state " << socketState);
    switch (socketState) {
    case STREAM_UNPLANNED_COMPLETE:
    case STREAM_FAILED:
         conn->close();
         return;

    case STREAM_NONE:
    case STREAM_COMPLETE:
        connState->flags.readMore = true;
        FtpChangeState(connState, ConnStateData::FTP_CONNECTED, "FtpWroteReply");
        if (connState->in.bodyParser)
            connState->finishDechunkingRequest(false);
        context->keepaliveNextRequest();
        return;
    }
}

bool
FtpHandleRequest(ClientSocketContext *context, String &cmd, String &params) {
    if (HttpRequest *request = context->http->request) {
        MemBuf *mb = new MemBuf;
        Packer p;
        mb->init();
        packerToMemInit(&p, mb);
        request->pack(&p);
        packerClean(&p);

        debugs(11, 2, "FTP Client " << context->clientConnection);
        debugs(11, 2, "FTP Client REQUEST:\n---------\n" << mb->buf <<
               "\n----------");
        delete mb;
    }

    static std::pair<const char *, FtpRequestHandler *> handlers[] = {
        std::make_pair("LIST", FtpHandleDataRequest),
        std::make_pair("NLST", FtpHandleDataRequest),
        std::make_pair("MLSD", FtpHandleDataRequest),
        std::make_pair("FEAT", FtpHandleFeatRequest),
        std::make_pair("PASV", FtpHandlePasvRequest),
        std::make_pair("PORT", FtpHandlePortRequest),
        std::make_pair("RETR", FtpHandleDataRequest),
        std::make_pair("EPRT", FtpHandleEprtRequest),
        std::make_pair("EPSV", FtpHandleEpsvRequest),
        std::make_pair("CWD", FtpHandleCwdRequest),
        std::make_pair("PASS", FtpHandlePassRequest),
        std::make_pair("CDUP", FtpHandleCdupRequest),
    };

    FtpRequestHandler *handler = NULL;
    if (context->http->request->method == Http::METHOD_PUT)
        handler = FtpHandleUploadRequest;
    else {
        for (size_t i = 0; i < sizeof(handlers) / sizeof(*handlers); ++i) {
            if (cmd.caseCmp(handlers[i].first) == 0) {
                handler = handlers[i].second;
                break;
            }
        }
    }

    return handler != NULL ? (*handler)(context, cmd, params) : true;
}

/// Called to parse USER command, which is required to create an HTTP request
/// wrapper. Thus, errors are handled with FtpWriteEarlyReply() here.
bool
FtpHandleUserRequest(ConnStateData *connState, const String &cmd, String &params)
{
    if (params.size() == 0) {
        FtpWriteEarlyReply(connState, 501, "Missing username");
        return false;
    }

    const String::size_type eou = params.rfind('@');
    if (eou == String::npos || eou + 1 >= params.size()) {
        FtpWriteEarlyReply(connState, 501, "Missing host");
        return false;
    }

    const String login = params.substr(0, eou);
    String host = params.substr(eou + 1, params.size());
    // If we can parse it as raw IPv6 address, then surround with "[]".
    // Otherwise (domain, IPv4, [bracketed] IPv6, garbage, etc), use as is.
    if (host.pos(":")) {
        char ipBuf[MAX_IPSTRLEN];
        Ip::Address ipa;
        ipa = host.termedBuf();
        if (!ipa.isAnyAddr()) {
            ipa.toHostStr(ipBuf, MAX_IPSTRLEN);
            host = ipBuf;
        }
    }
    connState->ftp.host = host;

    String oldUri;
    if (connState->ftp.readGreeting)
        oldUri = connState->ftp.uri;

    connState->ftpSetWorkingDir(NULL);
    connState->ftpBuildUri();

    if (!connState->ftp.readGreeting) {
        debugs(11, 3, "set URI to " << connState->ftp.uri);
    } else if (oldUri.caseCmp(connState->ftp.uri) == 0) {
        debugs(11, 5, "keep URI as " << oldUri);
    } else {
        debugs(11, 3, "reset URI from " << oldUri << " to " << connState->ftp.uri);
        FtpCloseDataConnection(connState);
        connState->ftp.readGreeting = false;
        connState->unpinConnection(true); // close control connection to the server
        FtpChangeState(connState, ConnStateData::FTP_BEGIN, "URI reset");
    }

    params.cut(eou);

    return true;
}

bool
FtpHandleFeatRequest(ClientSocketContext *context, String &cmd, String &params)
{
    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_FEAT, "FtpHandleFeatRequest");

    return true;
}

bool
FtpHandlePasvRequest(ClientSocketContext *context, String &cmd, String &params)
{
    ConnStateData *const connState = context->getConn();
    assert(connState);
    if (connState->ftp.gotEpsvAll) {
        FtpSetReply(context, 500, "Bad PASV command");
        return false;
    }

    if (params.size() > 0) {
        FtpSetReply(context, 501, "Unexpected parameter");
        return false;
    }

    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_PASV, "FtpHandlePasvRequest");
    // no need to fake PASV request via FtpSetDataCommand() in true PASV case
    return true;
}

/// [Re]initializes dataConn for active data transfers. Does not connect.
static
bool FtpCreateDataConnection(ClientSocketContext *context, Ip::Address cltAddr)
{
    ConnStateData *const connState = context->getConn();
    assert(connState);
    assert(connState->clientConnection != NULL);
    assert(!connState->clientConnection->remote.isAnyAddr());

    if (cltAddr != connState->clientConnection->remote) {
        debugs(33, 2, "rogue PORT " << cltAddr << " request? ctrl: " << connState->clientConnection->remote);
        // Closing the control connection would not help with attacks because
        // the client is evidently able to connect to us. Besides, closing
        // makes retrials easier for the client and more damaging to us.
        FtpSetReply(context, 501, "Prohibited parameter value");
        return false;
    }

    FtpCloseDataConnection(context->getConn());

    Comm::ConnectionPointer conn = new Comm::Connection();
    conn->remote = cltAddr;

    // Use local IP address of the control connection as the source address
    // of the active data connection, or some clients will refuse to accept.
    conn->flags |= COMM_DOBIND;
    conn->local = connState->clientConnection->local;
    // RFC 959 requires active FTP connections to originate from port 20
    // but that would preclude us from supporting concurrent transfers! (XXX?)
    conn->local.port(0);

    debugs(11, 3, "will actively connect from " << conn->local << " to " <<
           conn->remote);

    context->getConn()->ftp.dataConn = conn;
    context->getConn()->ftp.uploadAvailSize = 0;
    return true;
}

bool
FtpHandlePortRequest(ClientSocketContext *context, String &cmd, String &params)
{
    // TODO: Should PORT errors trigger FtpCloseDataConnection() cleanup?

    const ConnStateData *connState = context->getConn();
    if (connState->ftp.gotEpsvAll) {
        FtpSetReply(context, 500, "Rejecting PORT after EPSV ALL");
        return false;
    }

    if (!params.size()) {
        FtpSetReply(context, 501, "Missing parameter");
        return false;
    }

    Ip::Address cltAddr;
    if (!Ftp::ParseIpPort(params.termedBuf(), NULL, cltAddr)) {
        FtpSetReply(context, 501, "Invalid parameter");
        return false;
    }

    if (!FtpCreateDataConnection(context, cltAddr))
        return false;

    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_PORT, "FtpHandlePortRequest");
    FtpSetDataCommand(context);
    return true; // forward our fake PASV request
}

bool
FtpHandleDataRequest(ClientSocketContext *context, String &cmd, String &params)
{
    if (!FtpCheckDataConnPre(context))
        return false;

    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_DATA_REQUEST, "FtpHandleDataRequest");

    return true;
}

bool
FtpHandleUploadRequest(ClientSocketContext *context, String &cmd, String &params)
{
    if (!FtpCheckDataConnPre(context))
        return false;

    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_UPLOAD_REQUEST, "FtpHandleDataRequest");

    return true;
}

bool
FtpHandleEprtRequest(ClientSocketContext *context, String &cmd, String &params)
{
    debugs(11, 3, "Process an EPRT " << params);

    const ConnStateData *connState = context->getConn();
    if (connState->ftp.gotEpsvAll) {
        FtpSetReply(context, 500, "Rejecting EPRT after EPSV ALL");
        return false;
    }

    if (!params.size()) {
        FtpSetReply(context, 501, "Missing parameter");
        return false;
    }

    Ip::Address cltAddr;
    if (!Ftp::ParseProtoIpPort(params.termedBuf(), cltAddr)) {
        FtpSetReply(context, 501, "Invalid parameter");
        return false;
    }

    if (!FtpCreateDataConnection(context, cltAddr))
        return false;

    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_EPRT, "FtpHandleEprtRequest");
    FtpSetDataCommand(context);
    return true; // forward our fake PASV request
}

bool
FtpHandleEpsvRequest(ClientSocketContext *context, String &cmd, String &params)
{
    debugs(11, 3, "Process an EPSV command with params: " << params);
    if (params.size() <= 0) {
        // treat parameterless EPSV as "use the protocol of the ctrl conn"
    } else if (params.caseCmp("ALL") == 0) {
        ConnStateData *connState = context->getConn();
        FtpSetReply(context, 200, "EPSV ALL ok");
        connState->ftp.gotEpsvAll = true;
        return false;
    } else if (params.cmp("2") == 0) {
        if (!Ip::EnableIpv6) {
            FtpSetReply(context, 522, "Network protocol not supported, use (1)");
            return false;
        }
    } else if (params.cmp("1") != 0) {
        FtpSetReply(context, 501, "Unsupported EPSV parameter");
        return false;
    }

    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_EPSV, "FtpHandleEpsvRequest");
    FtpSetDataCommand(context);
    return true; // forward our fake PASV request
}

bool
FtpHandleCwdRequest(ClientSocketContext *context, String &cmd, String &params)
{
    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_CWD, "FtpHandleCwdRequest");
    return true;
}

bool
FtpHandlePassRequest(ClientSocketContext *context, String &cmd, String &params)
{
    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_PASS, "FtpHandlePassRequest");
    return true;
}

bool
FtpHandleCdupRequest(ClientSocketContext *context, String &cmd, String &params)
{
    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_CDUP, "FtpHandleCdupRequest");
    return true;
}

// Convert client PORT, EPRT, PASV, or EPSV data command to Squid PASV command.
// Squid server-side decides what data command to use on that side.
void
FtpSetDataCommand(ClientSocketContext *context)
{
    ClientHttpRequest *const http = context->http;
    assert(http != NULL);
    HttpRequest *const request = http->request;
    assert(request != NULL);
    HttpHeader &header = request->header;
    header.delById(HDR_FTP_COMMAND);
    header.putStr(HDR_FTP_COMMAND, "PASV");
    header.delById(HDR_FTP_ARGUMENTS);
    header.putStr(HDR_FTP_ARGUMENTS, "");
    debugs(11, 5, "client data command converted to fake PASV");
}

/// check that client data connection is ready for future I/O or at least
/// has a chance of becoming ready soon.
bool
FtpCheckDataConnPre(ClientSocketContext *context)
{
    ConnStateData *const connState = context->getConn();
    if (Comm::IsConnOpen(connState->ftp.dataConn))
        return true;

    if (Comm::IsConnOpen(connState->ftp.dataListenConn)) {
        // We are still waiting for a client to connect to us after PASV.
        // Perhaps client's data conn handshake has not reached us yet.
        // After we talk to the server, FtpCheckDataConnPost() will recheck.
        debugs(33, 3, "expecting clt data conn " << connState->ftp.dataListenConn);
        return true;
    }

    if (!connState->ftp.dataConn || connState->ftp.dataConn->remote.isAnyAddr()) {
        debugs(33, 5, "missing " << connState->ftp.dataConn);
        // TODO: use client address and default port instead.
        FtpSetReply(context, 425, "Use PORT or PASV first");
        return false;
    }

    // active transfer: open a connection from Squid to client
    AsyncCall::Pointer connector = context->getConn()->ftp.connector =
        commCbCall(17, 3, "FtpConnectDoneWrapper", 
                   CommConnectCbPtrFun(FtpHandleConnectDone, context));

    Comm::ConnOpener *cs = new Comm::ConnOpener(connState->ftp.dataConn,
                                                connector,
                                                Config.Timeout.connect);
    AsyncJob::Start(cs);
    return false; // ConnStateData::processFtpRequest waits FtpHandleConnectDone
}

/// Check that client data connection is ready for immediate I/O.
static bool
FtpCheckDataConnPost(ClientSocketContext *context)
{
    ConnStateData *connState = context->getConn();
    assert(connState);
    const Comm::ConnectionPointer &dataConn = connState->ftp.dataConn;
    if (!Comm::IsConnOpen(dataConn)) {
        debugs(33, 3, "missing client data conn: " << dataConn);
        return false;
    }
    return true;
}

void
FtpHandleConnectDone(const Comm::ConnectionPointer &conn, Comm::Flag status, int xerrno, void *data)
{
    ClientSocketContext *context = static_cast<ClientSocketContext*>(data);
    context->getConn()->ftp.connector = NULL;

    if (status != Comm::OK) {
        conn->close();
        FtpSetReply(context, 425, "Cannot open data connection.");
        assert(context->http && context->http->storeEntry() != NULL);
    } else {
        assert(context->getConn()->ftp.dataConn == conn);
        assert(Comm::IsConnOpen(conn));
        fd_note(conn->fd, "active client ftp data");
    }
    context->getConn()->resumeFtpRequest(context);
}

void
FtpSetReply(ClientSocketContext *context, const int code, const char *msg)
{
    ClientHttpRequest *const http = context->http;
    assert(http != NULL);
    assert(http->storeEntry() == NULL);

    HttpReply *const reply = new HttpReply;
    reply->sline.set(Http::ProtocolVersion(1, 1), Http::scNoContent);
    HttpHeader &header = reply->header;
    header.putTime(HDR_DATE, squid_curtime);
    {
        HttpHdrCc cc;
        cc.Private();
        header.putCc(&cc);
    }
    header.putInt64(HDR_CONTENT_LENGTH, 0);
    header.putInt(HDR_FTP_STATUS, code);
    header.putStr(HDR_FTP_REASON, msg);
    reply->hdrCacheInit();

    setLogUri(http, urlCanonicalClean(http->request));

    clientStreamNode *const node = context->getClientReplyContext();
    clientReplyContext *const repContext =
        dynamic_cast<clientReplyContext *>(node->data.getRaw());
    assert(repContext != NULL);

    RequestFlags flags;
    flags.cachable = false; // force releaseRequest() in storeCreateEntry()
    flags.noCache = true;
    repContext->createStoreEntry(http->request->method, flags);
    http->storeEntry()->replaceHttpReply(reply);
}

/// Whether Squid FTP gateway supports a given feature (e.g., a command).
static bool
FtpSupportedCommand(const String &name)
{
    static std::set<std::string> BlackList;
    if (BlackList.empty()) {
        /* Add FTP commands that Squid cannot gateway correctly */

        // we probably do not support AUTH TLS.* and AUTH SSL,
        // but let's disclaim all AUTH support to KISS, for now
        BlackList.insert("AUTH");
    }

    // we claim support for all commands that we do not know about
    return BlackList.find(name.termedBuf()) == BlackList.end();
}
