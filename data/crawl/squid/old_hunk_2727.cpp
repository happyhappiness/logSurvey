                storeAppendPrintf(sentry, " %%USER_CERT_%s", format->header);
                break;
#endif

                DUMP_EXT_ACL_TYPE(EXT_USER);

            default:
                fatal("unknown external_acl format error");
                break;
