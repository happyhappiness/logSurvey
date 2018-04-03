        handleControlReply();
    } else {
        /* XXX What about Config.Timeout.read? */
        comm_read(ctrl.fd, ctrl.buf + ctrl.offset, ctrl.size - ctrl.offset, ftpReadControlReply, this);
        /*
         * Cancel the timeout on the Data socket (if any) and
         * establish one on the control socket.
         */

        if (data.fd > -1)
            commSetTimeout(data.fd, -1, NULL, NULL);

        commSetTimeout(ctrl.fd, Config.Timeout.read, ftpTimeout,
                       this);
    }
}

void
FtpStateData::ftpReadControlReply(int fd, char *buf, size_t len, comm_err_t errflag, int xerrno, void *data)
{
    FtpStateData *ftpState = (FtpStateData *)data;
    StoreEntry *entry = ftpState->entry;
    debugs(9, 3, HERE "FD " << fd << ", Read " << len << " bytes");

    if (len > 0) {
        kb_incr(&statCounter.server.all.kbytes_in, len);
        kb_incr(&statCounter.server.ftp.kbytes_in, len);
    }

    if (errflag == COMM_ERR_CLOSING)
        return;

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        ftpState->abortTransaction("entry aborted during control reply read");
        return;
    }

    assert(ftpState->ctrl.offset < ftpState->ctrl.size);

    if (errflag == COMM_OK && len > 0) {
        fd_bytes(fd, len, FD_READ);
    }


    if (errflag != COMM_OK || len < 0) {
         debugs(50, ignoreErrno(xerrno) ? 3 : DBG_IMPORTANT, "ftpReadControlReply: read error: " << xstrerr(xerrno));

        if (ignoreErrno(xerrno)) {
            ftpState->scheduleReadControlReply(0);
        } else {
            ftpState->failed(ERR_READ_ERROR, xerrno);
            /* failed closes ctrl.fd and frees ftpState */
            return;
        }

        return;
    }

    if (len == 0) {
        if (entry->store_status == STORE_PENDING) {
            ftpState->failed(ERR_FTP_FAILURE, 0);
            /* failed closes ctrl.fd and frees ftpState */
            return;
        }

    /* XXX this may end up having to be serverComplete() .. */
        ftpState->abortTransaction("zero control reply read");
        return;
    }

    len += ftpState->ctrl.offset;
    ftpState->ctrl.offset = len;
    assert(len <= ftpState->ctrl.size);
    ftpState->handleControlReply();
}

void
