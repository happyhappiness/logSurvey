        break;

    default:
        memBufPrintf(&mb, "%%%c", token);

        do_quote = 0;

