    }

    if (callback_ != NULL) {
        typedef CommConnectCbParams Params;
        Params &params = GetCommParams<Params>(callback_);
        params.conn = conn_;
        params.flag = errFlag;
        params.xerrno = xerrno;
        ScheduleCallHere(callback_);
        callback_ = NULL;
    }

    if (temporaryFd_ >= 0) {
        debugs(5, 4, HERE << conn_ << " closing temp FD " << temporaryFd_);
        // it never reached fully open, so cleanup the FD handlers
        // Note that comm_close() sequence does not happen for partially open FD
        Comm::SetSelect(temporaryFd_, COMM_SELECT_WRITE, NULL, NULL, 0);
        calls_.earlyAbort_ = NULL;
        if (calls_.timeout_ != NULL) {
            calls_.timeout_->cancel("Comm::ConnOpener::doneConnecting");
            calls_.timeout_ = NULL;
        }
        fd_table[temporaryFd_].timeoutHandler = NULL;
        fd_table[temporaryFd_].timeout = 0;
        close(temporaryFd_);
        fd_close(temporaryFd_);
        temporaryFd_ = -1;
    }

    /* ensure cleared local state, we are done. */
    conn_ = NULL;
}

void
Comm::ConnOpener::start()
{
    Must(conn_ != NULL);

    /* get a socket open ready for connecting with */
    if (temporaryFd_ < 0) {
        /* outbound sockets have no need to be protocol agnostic. */
        if (!(Ip::EnableIpv6&IPV6_SPECIAL_V4MAPPING) && conn_->remote.IsIPv4()) {
            conn_->local.SetIPv4();
        }
        temporaryFd_ = comm_openex(SOCK_STREAM, IPPROTO_TCP, conn_->local, conn_->flags, conn_->tos, conn_->nfmark, host_);
        if (temporaryFd_ < 0) {
            doneConnecting(COMM_ERR_CONNECT, 0);
            return;
        }
    }

    typedef CommCbMemFunT<Comm::ConnOpener, CommCloseCbParams> abortDialer;
