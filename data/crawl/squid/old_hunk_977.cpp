        break;

    case 't':
        mb.Printf("%s", Time::FormatHttpd(squid_curtime));
        break;

    case 'T':
        mb.Printf("%s", mkrfc1123(squid_curtime));
        break;

    case 'U':
