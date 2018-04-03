
    case 'p':
        if (request) {
            mb.Printf("%d", (int) request->port);
        } else if (!building_deny_info_url) {
            p = "[unknown port]";
        }
