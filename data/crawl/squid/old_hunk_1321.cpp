    }

    fwd->handleUnregisteredServerEnd();
    mustStop("ServerStateData::abortTransaction");
}

/**
 * Cancel the timeout on the Control socket and establish one
 * on the data socket
 */
void
ServerStateData::switchTimeoutToDataChannel()
{
    commUnsetConnTimeout(ctrl.conn);

    typedef CommCbMemFunT<ServerStateData, CommTimeoutCbParams> TimeoutDialer;
    AsyncCall::Pointer timeoutCall = JobCallback(9, 5, TimeoutDialer, this,
                                                 ServerStateData::timeout);
    commSetConnTimeout(data.conn, Config.Timeout.read, timeoutCall);
}

void
ServerStateData::sentRequestBody(const CommIoCbParams &io)
{
    if (io.size > 0)
        kb_incr(&(statCounter.server.ftp.kbytes_out), io.size);
