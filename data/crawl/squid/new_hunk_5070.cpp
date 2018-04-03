                storeAppendPrintf(sentry, " %%USER_CERT");
                break;

            case _external_acl_format::EXT_ACL_USER_CERTCHAIN_RAW:
                storeAppendPrintf(sentry, " %%USER_CERTCHAIN");
                break;

            case _external_acl_format::EXT_ACL_USER_CERT:
                storeAppendPrintf(sentry, " %%USER_CERT_%s", format->header);
                break;
