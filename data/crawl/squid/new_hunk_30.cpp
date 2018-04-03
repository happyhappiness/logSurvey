            break;

        case Log::Format::CLF_SQUID:
            // this is the default, no need to add to the dump
            //storeAppendPrintf(entry, "%s logformat=squid", log->filename);
            break;

        case Log::Format::CLF_COMBINED:
