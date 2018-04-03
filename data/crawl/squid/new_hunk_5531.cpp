	    storeAppendPrintf(sentry, " concurrency=%d", node->children);
	for (format = node->format; format; format = format->next) {
	    switch (format->type) {
	    case _external_acl_format::EXT_ACL_HEADER:
	    case _external_acl_format::EXT_ACL_HEADER_ID:
		storeAppendPrintf(sentry, " %%{%s}", format->header);
		break;
	    case _external_acl_format::EXT_ACL_HEADER_MEMBER:
	    case _external_acl_format::EXT_ACL_HEADER_ID_MEMBER:
		storeAppendPrintf(sentry, " %%{%s:%s}", format->header, format->member);
		break;
#define DUMP_EXT_ACL_TYPE(a) \
	    case _external_acl_format::EXT_ACL_##a: \
		storeAppendPrintf(sentry, " %%%s", #a); \
		break
		DUMP_EXT_ACL_TYPE(LOGIN);
