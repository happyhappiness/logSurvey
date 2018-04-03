        break;

    case 'w':

        if (Config.adminEmail)
            mb.Printf("%s", Config.adminEmail);
        else
            p = "[unknown]";

        break;

    case 'W':
        if (Config.adminEmail && Config.onoff.emailErrData)
            Dump(&mb);

        break;

    case 'z':
        if (dnsError.size() > 0)
            p = dnsError.termedBuf();
        else
            p = "[unknown]";

        break;

    case 'Z':
        if (err_msg)
            p = err_msg;
        else
            p = "[unknown]";

        break;

    case '%':
        p = "%";

        break;

    default:
        mb.Printf("%%%c", token);

        do_quote = 0;

        break;
    }

