    case 'w':

        if (Config.adminEmail)
            mb.Printf("%s", Config.adminEmail);
        else
            p = "[unknown]";

