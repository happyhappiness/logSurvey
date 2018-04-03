        else
            urlpath_or_slash = "/";

        str.Printf(SQUIDSBUFPH " " SQUIDSTRINGPH " %s/%d.%d\n",
                   SQUIDSBUFPRINT(request->method.image()),
                   SQUIDSTRINGPRINT(urlpath_or_slash),
                   AnyP::ProtocolType_str[request->http_ver.protocol],
                   request->http_ver.major, request->http_ver.minor);
        request->header.packInto(&str);
    }

    str.Printf("\r\n");
    /* - FTP stuff */

    if (ftp.request) {
        str.Printf("FTP Request: %s\r\n", ftp.request);
        str.Printf("FTP Reply: %s\r\n", (ftp.reply? ftp.reply:"[none]"));
        str.Printf("FTP Msg: ");
        wordlistCat(ftp.server_msg, &str);
        str.Printf("\r\n");
    }

    str.Printf("\r\n");
    mb->Printf("&body=%s", rfc1738_escape_part(str.buf));
    str.clean();
    return 0;
}
