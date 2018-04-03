            break;

        case Log::Format::CLF_SQUID:
            storeAppendPrintf(entry, "%s logformat=squid", log->filename);
            break;

        case Log::Format::CLF_COMBINED:
