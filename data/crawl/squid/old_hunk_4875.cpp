        break;

    case 'I':
        if (err->host) {
            mb.Printf("%s", err->host);
        } else
            p = "[unknown]";

