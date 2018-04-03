    return true;
}

bool
Ftp::Gateway::mayReadVirginReplyBody() const
{
    // TODO: Can we do what Ftp::Relay::mayReadVirginReplyBody() does instead?
    return !doneWithServer();
}

AsyncJob::Pointer
Ftp::StartGateway(FwdState *const fwdState)
{
    return AsyncJob::Start(new Ftp::Gateway(fwdState));
}
