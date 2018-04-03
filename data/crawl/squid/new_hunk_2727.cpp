                storeAppendPrintf(sentry, " %%USER_CERT_%s", format->header);
                break;
#endif
#if USE_AUTH
                DUMP_EXT_ACL_TYPE(EXT_USER);
#endif
            default:
                fatal("unknown external_acl format error");
                break;
