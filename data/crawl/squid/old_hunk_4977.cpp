
    case 'p':
        if (r) {
            memBufPrintf(&mb, "%d", (int) r->port);
        } else {
            p = "[unknown port]";
        }
