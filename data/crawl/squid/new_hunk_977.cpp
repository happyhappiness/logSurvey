        break;

    case 't':
        mb.appendf("%s", Time::FormatHttpd(squid_curtime));
        break;

    case 'T':
        mb.appendf("%s", mkrfc1123(squid_curtime));
        break;

    case 'U':
