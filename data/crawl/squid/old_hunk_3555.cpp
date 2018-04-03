                p = request->hier.host;
            else
                p = request->GetHost();
        } else
            p = "[unknown host]";

        break;

    case 'i':
        mb.Printf("%s", src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));

        break;

    case 'I':
        if (request && request->hier.host[0] != '\0') // if non-empty string
            mb.Printf("%s", request->hier.host);
        else
            p = "[unknown]";

        break;

    case 'l':
        mb.append(error_stylesheet.content(), error_stylesheet.contentSize());
        do_quote = 0;
        break;

    case 'L':
        if (Config.errHtmlText) {
            mb.Printf("%s", Config.errHtmlText);
            do_quote = 0;
        } else
            p = "[not available]";

        break;

    case 'm':
        p = auth_user_request->denyMessage("[not available]");

        break;

    case 'M':
        p = request ? RequestMethodStr(request->method) : "[unknown method]";

        break;

    case 'o':
        p = external_acl_message ? external_acl_message : "[not available]";

        break;

    case 'p':
        if (request) {
            mb.Printf("%d", (int) request->port);
        } else {
            p = "[unknown port]";
        }

        break;

    case 'P':
        p = request ? ProtocolStr[request->protocol] : "[unknown protocol]";
        break;

    case 'R':

        if (NULL != request) {
            Packer p;
            String urlpath_or_slash;
