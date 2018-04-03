    ftpReadQuit,		/* SENT_QUIT */
    ftpReadTransferDone,	/* READING_DATA (RETR,LIST,NLST) */
    ftpWriteTransferDone,	/* WRITING_DATA (STOR) */
    ftpReadMkdir,		/* SENT_MKDIR */
    NULL,			/* SENT_FEAT */
    NULL,			/* SENT_PWD */
    NULL,			/* SENT_CDUP*/
    NULL,			/* SENT_DATA_REQUEST */
    NULL			/* SENT_COMMAND */
};

/// handler called by Comm when FTP data channel is closed unexpectedly
void
Ftp::Gateway::dataClosed(const CommCloseCbParams &io)
{
    Ftp::Client::dataClosed(io);
    failed(ERR_FTP_FAILURE, 0);
    /* failed closes ctrl.conn and frees ftpState */

