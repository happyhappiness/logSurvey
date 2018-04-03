        else
            urlpath_or_slash = "/";

        str.appendf(SQUIDSBUFPH " " SQUIDSTRINGPH " %s/%d.%d\n",
                    SQUIDSBUFPRINT(request->method.image()),
                    SQUIDSTRINGPRINT(urlpath_or_slash),
                    AnyP::ProtocolType_str[request->http_ver.protocol],
                    request->http_ver.major, request->http_ver.minor);
        request->header.packInto(&str);
    }

    str.append("\r\n", 2);
    /* - FTP stuff */

    if (ftp.request) {
        str.appendf("FTP Request: %s\r\n", ftp.request);
        str.appendf("FTP Reply: %s\r\n", (ftp.reply? ftp.reply:"[none]"));
        str.append("FTP Msg: ", 9);
        wordlistCat(ftp.server_msg, &str);
        str.append("\r\n", 2);
    }

    str.append("\r\n", 2);
    mb->appendf("&body=%s", rfc1738_escape_part(str.buf));
    str.clean();
    return 0;
}
