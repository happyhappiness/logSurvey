    case ACL_IDENT: 
#endif
    case ACL_DERIVED:
    case ACL_PROXY_AUTH:
	fatal ("unused");
	break;
    case ACL_PROXY_AUTH_REGEX:
	if (authenticateSchemeCount() == 0) {
	    debug(28, 0) ("aclParseAclLine: IGNORING: Proxy Auth ACL '%s' \
because no authentication schemes were compiled.\n", cfgline);
	} else if (authenticateActiveSchemeCount() == 0) {
	    debug(28, 0) ("aclParseAclLine: IGNORING: Proxy Auth ACL '%s' \
because no authentication schemes are fully configured.\n", cfgline);
	} else {
	    aclParseRegexList(&data);
	}
	break;
#if SQUID_SNMP
    case ACL_SNMP_COMMUNITY:
