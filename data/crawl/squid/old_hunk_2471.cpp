        break;

    case 'I':
        if (request && request->hier.host[0] != '\0') // if non-empty string
            mb.Printf("%s", request->hier.host);
        else if (!building_deny_info_url)
            p = "[unknown]";
        break;