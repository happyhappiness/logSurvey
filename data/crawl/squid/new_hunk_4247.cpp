        break;

    case 'H':
        if (request) {
            if (request->hier.host)
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
        if (request && request->hier.host) {
            mb.Printf("%s", request->hier.host);
        } else
            p = "[unknown]";

