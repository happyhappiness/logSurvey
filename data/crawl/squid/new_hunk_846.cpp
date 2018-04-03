
    case 'p':
        if (request) {
            mb.appendf("%u", request->port);
        } else if (!building_deny_info_url) {
            p = "[unknown port]";
        }
