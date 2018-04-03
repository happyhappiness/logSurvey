            case _external_acl_format::EXT_ACL_##a: \
                storeAppendPrintf(sentry, " %%%s", #a); \
                break
#if USE_AUTH
                DUMP_EXT_ACL_TYPE(LOGIN);
#endif
