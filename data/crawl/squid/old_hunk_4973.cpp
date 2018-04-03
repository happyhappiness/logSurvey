        p = "[none]";
    }

    memBufPrintf(&str, "\r\n");
    /* - FTP stuff */

    if (err->ftp.request) {
        memBufPrintf(&str, "FTP Request: %s\r\n", err->ftp.request);
        memBufPrintf(&str, "FTP Reply: %s\r\n", err->ftp.reply);
        memBufPrintf(&str, "FTP Msg: ");
        wordlistCat(err->ftp.server_msg, &str);
        memBufPrintf(&str, "\r\n");
    }

    memBufPrintf(&str, "\r\n");
    memBufPrintf(mb, "&body=%s", rfc1738_escape_part(str.buf));
    memBufClean(&str);
    return 0;
}

