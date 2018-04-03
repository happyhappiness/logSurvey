            if (r->hier.host)
                p = r->hier.host;
            else
                p = r->host;
        } else
            p = "[unknown host]";

        break;

    case 'i':
        mb.Printf("%s", inet_ntoa(err->src_addr));

        break;

