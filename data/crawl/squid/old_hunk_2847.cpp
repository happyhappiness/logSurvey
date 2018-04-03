
        switch (log->type) {

        case CLF_CUSTOM:
            storeAppendPrintf(entry, "%s %s", log->filename, log->logFormat->name);
            break;

        case CLF_NONE:
            storeAppendPrintf(entry, "none");
            break;

        case CLF_SQUID:
            storeAppendPrintf(entry, "%s squid", log->filename);
            break;

        case CLF_COMMON:
            storeAppendPrintf(entry, "%s squid", log->filename);
            break;
#if ICAP_CLIENT
        case CLF_ICAP_SQUID:
            storeAppendPrintf(entry, "%s icap_squid", log->filename);
            break;
#endif
        case CLF_AUTO:

            if (log->aclList)
                storeAppendPrintf(entry, "%s auto", log->filename);
            else
                storeAppendPrintf(entry, "%s", log->filename);

            break;

        case CLF_UNKNOWN:
            break;
        }
