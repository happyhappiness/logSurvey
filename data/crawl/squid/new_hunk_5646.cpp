	/* NOTREACHED */
    case ACL_PROXY_AUTH:
    case ACL_PROXY_AUTH_REGEX:
	if ((ti = aclAuthenticated(checklist)) != 0)
	    return ti;
	ti = aclMatchProxyAuth(ae->data, checklist->auth_user_request,
	    checklist, ae->type);
	checklist->auth_user_request = NULL;
	return ti;
	/* NOTREACHED */
    case ACL_MAX_USER_IP:
	if ((ti = aclAuthenticated(checklist)) != 0)
	    return ti;
	ti = aclMatchUserMaxIP(ae->data, checklist->auth_user_request,
	    checklist->src_addr);
	checklist->auth_user_request = NULL;
	return ti;
	/* NOTREACHED */
#if SQUID_SNMP
    case ACL_SNMP_COMMUNITY:
	return aclMatchWordList(ae->data, checklist->snmp_community);
	/* NOTREACHED */
#endif
    case ACL_SRC_ASN:
	return asnMatchIp(ae->data, checklist->src_addr);
	/* NOTREACHED */
    case ACL_DST_ASN:
	ia = ipcache_gethostbyname(r->host, IP_LOOKUP_IF_MISS);
	if (ia) {
