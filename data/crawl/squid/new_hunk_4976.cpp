        break;

    case 'i':
        mb.Printf("%s", inet_ntoa(err->src_addr));

        break;

    case 'I':
        if (err->host) {
            mb.Printf("%s", err->host);
        } else
            p = "[unknown]";

        break;

    case 'L':
        if (Config.errHtmlText) {
            mb.Printf("%s", Config.errHtmlText);
            do_quote = 0;
        } else
            p = "[not available]";
