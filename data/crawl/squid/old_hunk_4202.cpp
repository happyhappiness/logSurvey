FtpStateData::dataClosed(const CommCloseCbParams &io)
{
    data.clear();
    failed(ERR_FTP_FAILURE, 0); // or is it better to call abortTransaction()?
    /* failed closes ctrl.fd and frees ftpState */
}

FtpStateData::FtpStateData(FwdState *theFwdState) : AsyncJob("FtpStateData"), ServerStateData(theFwdState)
