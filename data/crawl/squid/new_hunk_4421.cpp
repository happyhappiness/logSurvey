            if (r->hier.host)
                p = r->hier.host;
            else
                p = r->GetHost();
        } else
            p = "[unknown host]";

        break;

    case 'i':
        mb.Printf("%s", err->src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));

        break;

