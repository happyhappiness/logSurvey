                         reply->header.getStr(HDR_FTP_REASON):
                         reply->sline.reason();

    mb.appendf("%i %s\r\n", scode, reason); // error terminating line

    // TODO: errorpage.cc should detect FTP client and use
    // configurable FTP-friendly error templates which we should
