    case 'w':

        if (Config.adminEmail)
            memBufPrintf(&mb, "%s", Config.adminEmail);
        else
            p = "[unknown]";

