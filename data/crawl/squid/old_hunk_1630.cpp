        connState->ftp.dataConn = params.conn;
        connState->ftp.uploadAvailSize = 0;
        debugs(33, 7, "ready for data");
    }
}

