        ftpReadMkdir		/* SENT_MKDIR */
    };

void 
FtpStateData::ftpSocketClosed(const CommCloseCbParams &io)
{
    ctrl.fd = -1;
    deleteThis("FtpStateData::ftpSocketClosed");
}

FtpStateData::FtpStateData(FwdState *theFwdState) : AsyncJob("FtpStateData"), ServerStateData(theFwdState)
