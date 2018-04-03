    ftpReadQuit,		/* SENT_QUIT */
    ftpReadTransferDone,	/* READING_DATA (RETR,LIST,NLST) */
    ftpWriteTransferDone,	/* WRITING_DATA (STOR) */
    ftpReadMkdir		/* SENT_MKDIR */
};

/// handler called by Comm when FTP control channel is closed unexpectedly
void
FtpStateData::ctrlClosed(const CommCloseCbParams &io)
{
    debugs(9, 4, HERE);
    ctrl.clear();
    mustStop("FtpStateData::ctrlClosed");
}

/// handler called by Comm when FTP data channel is closed unexpectedly
void
FtpStateData::dataClosed(const CommCloseCbParams &io)
{
    debugs(9, 4, HERE);
    if (data.listenConn != NULL) {
        data.listenConn->close();
        data.listenConn = NULL;
        // NP clear() does the: data.fd = -1;
    }
    data.clear();
    failed(ERR_FTP_FAILURE, 0);
    /* failed closes ctrl.conn and frees ftpState */

