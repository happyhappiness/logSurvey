        break;

    case 'I':
        if (r && r->hier.host) {
            mb.Printf("%s", r->hier.host);
        } else
            p = "[unknown]";

