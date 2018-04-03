                storeAppendPrintf(sentry, " %%{%s:%s}", format->header, format->member);
                break;
#define DUMP_EXT_ACL_TYPE(a) \
	    case _external_acl_format::EXT_ACL_##a: \
		storeAppendPrintf(sentry, " %%%s", #a); \
		break

                DUMP_EXT_ACL_TYPE(LOGIN);
#if USE_IDENT
