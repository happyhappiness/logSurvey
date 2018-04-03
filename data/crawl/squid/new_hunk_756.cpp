    case 'x':
#if USE_OPENSSL
        if (detail)
            mb.appendf("%s", detail->errorName());
        else
#endif
            if (!building_deny_info_url)
