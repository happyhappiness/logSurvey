        case CLF_COMMON:
            storeAppendPrintf(entry, "%s squid", log->filename);
            break;

        case CLF_AUTO:

            if (log->aclList)
