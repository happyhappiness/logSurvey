        break;

    case 'i':
        memBufPrintf(&mb, "%s", inet_ntoa(err->src_addr));

        break;

    case 'I':
        if (err->host) {
            memBufPrintf(&mb, "%s", err->host);
        } else
            p = "[unknown]";

        break;

    case 'L':
        if (Config.errHtmlText) {
            memBufPrintf(&mb, "%s", Config.errHtmlText);
            do_quote = 0;
        } else
            p = "[not available]";
