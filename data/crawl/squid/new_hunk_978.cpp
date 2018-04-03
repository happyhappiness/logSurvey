
    case 'w':
        if (Config.adminEmail)
            mb.appendf("%s", Config.adminEmail);
        else if (!building_deny_info_url)
            p = "[unknown]";
        break;
