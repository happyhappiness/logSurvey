        p = "[none]";
    }

    str.Printf("\r\n");
    /* - FTP stuff */

    if (err->ftp.request) {
        str.Printf("FTP Request: %s\r\n", err->ftp.request);
        str.Printf("FTP Reply: %s\r\n", err->ftp.reply);
        str.Printf("FTP Msg: ");
        wordlistCat(err->ftp.server_msg, &str);
        str.Printf("\r\n");
    }

    str.Printf("\r\n");
    mb->Printf("&body=%s", rfc1738_escape_part(str.buf));
    str.clean();
    return 0;
}

