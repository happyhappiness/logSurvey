
    context->getConn()->ftp.dataConn = conn;
    context->getConn()->ftp.uploadAvailSize = 0;

    FtpChangeState(context->getConn(), ConnStateData::FTP_HANDLE_PORT, "FtpHandlePortRequest");

    // convert client PORT command to Squid PASV command because Squid
    // does not support active FTP transfers on the server side (yet?)
    ClientHttpRequest *const http = context->http;
    assert(http != NULL);
    HttpRequest *const request = http->request;
    assert(request != NULL);
    HttpHeader &header = request->header;
    header.delById(HDR_FTP_COMMAND);
    header.putStr(HDR_FTP_COMMAND, "PASV");
    header.delById(HDR_FTP_ARGUMENTS);
    header.putStr(HDR_FTP_ARGUMENTS, "");
    return true; // forward our fake PASV request
}

