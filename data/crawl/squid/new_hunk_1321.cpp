    }

    fwd->handleUnregisteredServerEnd();
    mustStop("Ftp::Client::abortTransaction");
}

/**
 * Cancel the timeout on the Control socket and establish one
 * on the data socket
 */
void
Ftp::Client::switchTimeoutToDataChannel()
{
    commUnsetConnTimeout(ctrl.conn);

    typedef CommCbMemFunT<Client, CommTimeoutCbParams> TimeoutDialer;
    AsyncCall::Pointer timeoutCall = JobCallback(9, 5, TimeoutDialer, this,
                                                 Ftp::Client::timeout);
    commSetConnTimeout(data.conn, Config.Timeout.read, timeoutCall);
}

void
Ftp::Client::sentRequestBody(const CommIoCbParams &io)
{
    if (io.size > 0)
        kb_incr(&(statCounter.server.ftp.kbytes_out), io.size);
