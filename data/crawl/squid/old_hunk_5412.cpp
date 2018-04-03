    case ACL_IDENT:
#endif
    case ACL_DERIVED:
    case ACL_PROXY_AUTH:
	fatal ("unused");
    case ACL_TIME:
	return aclDumpTimeSpecList((acl_time_data *)data);
    case ACL_PROXY_AUTH_REGEX:
    case ACL_URL_REGEX:
    case ACL_URLPATH_REGEX:
    case ACL_BROWSER:
