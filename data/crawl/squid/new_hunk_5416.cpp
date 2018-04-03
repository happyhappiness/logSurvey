    case ACL_DST_DOM_REGEX:
    case ACL_REQ_MIME_TYPE:
    case ACL_REP_MIME_TYPE:
	aclParseRegexList(&data);
	break;
    case ACL_SRC_ASN:
    case ACL_MAXCONN:
    case ACL_DST_ASN:
	aclParseIntlist(&data);
	break;
    case ACL_MAX_USER_IP:
	aclParseUserMaxIP(&data);
	break;
#if SRC_RTT_NOT_YET_FINISHED
    case ACL_NETDB_SRC_RTT:
	aclParseIntlist(&data);
	break;
#endif
    case ACL_URL_PORT:
    case ACL_MY_PORT:
	aclParseIntRange(&data);
	break;
#if USE_IDENT
    case ACL_IDENT_REGEX:
	aclParseRegexList(&data);
	break;
#endif
    case ACL_PROTO:
	aclParseProtoList(&data);
	break;
    case ACL_METHOD:
	aclParseMethodList(&data);
	break;
#if USE_IDENT
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
	aclParseWordList(&data);
	break;
#endif
#if USE_ARP_ACL
    case ACL_SRC_ARP:
	aclParseArpList(&data);
	break;
#endif
    case ACL_EXTERNAL:
	aclParseExternal(&data);
	break;
#if USE_SSL
    case ACL_USER_CERT:
    case ACL_CA_CERT:
	aclParseCertList(&data);
	break;
#endif
    case ACL_NONE:
    case ACL_ENUM_MAX:
	fatal("Bad ACL type");
	break;
    }
}

/* does name lookup, returns page_id */
