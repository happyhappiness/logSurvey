        ftpReadMkdir		/* SENT_MKDIR */
    };

/// close handler called by Comm when FTP control channel is closed prematurely
void 
FtpStateData::ctrlClosed(const CommCloseCbParams &io)
{
    ctrl.clear();
    deleteThis("FtpStateData::ctrlClosed");
}

/// close handler called by Comm when FTP data channel is closed prematurely
void 
FtpStateData::dataClosed(const CommCloseCbParams &io)
{
    data.clear();
    deleteThis("FtpStateData::dataClosed");
}

FtpStateData::FtpStateData(FwdState *theFwdState) : AsyncJob("FtpStateData"), ServerStateData(theFwdState)
