#endif
            p = "-";
        break;
    case 'B':
        if (building_deny_info_url) break;
        p = request ? ftpUrlWith2f(request) : "[no URL]";