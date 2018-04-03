    Ftp::Client::scheduleReadControlReply(0);
}

void
Ftp::Relay::finalizeDataDownload()
{
    debugs(9, 2, "Complete data downloading/Uploading");

    updateMaster().waitForOriginData = false;

    CbcPointer<ConnStateData> &mgr = fwd->request->clientConnectionManager;
    if (mgr.valid()) {
        if (Ftp::Server *srv = dynamic_cast<Ftp::Server*>(mgr.get())) {
            typedef NullaryMemFunT<Ftp::Server> CbDialer;
            AsyncCall::Pointer call = JobCallback(11, 3, CbDialer, srv,
                                                        Ftp::Server::originDataCompletionCheckpoint);
            ScheduleCallHere(call);
        }
    }
    serverComplete();
}

bool
Ftp::Relay::abortOnData(const char *reason)
{
    debugs(9, 3, "aborting transaction for " << reason <<
           "; FD " << (ctrl.conn != NULL ? ctrl.conn->fd : -1) << ", Data FD " << (data.conn != NULL ? data.conn->fd : -1) << ", this " << this);
    // this method is only called to handle data connection problems
    // the control connection should keep going

#if USE_ADAPTATION
    if (adaptedBodySource != NULL)
        stopConsumingFrom(adaptedBodySource);
#endif

    if (Comm::IsConnOpen(data.conn))
        dataComplete();

    return !Comm::IsConnOpen(ctrl.conn);
}

void
Ftp::Relay::abort(void *d)
{
    Ftp::Relay *ftpClient = (Ftp::Relay *)d;
    debugs(9, 2, "Client Data connection closed!");
    if (!cbdataReferenceValid(ftpClient))
        return;
    if (Comm::IsConnOpen(ftpClient->data.conn))
        ftpClient->dataComplete();
}

AsyncJob::Pointer
Ftp::StartRelay(FwdState *const fwdState)
{
