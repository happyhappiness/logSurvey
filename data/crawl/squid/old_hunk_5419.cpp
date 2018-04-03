}

wordlist *
aclDumpGeneric(const acl * a)
{
    debug(28, 3) ("aclDumpGeneric: %s type %d\n", a->name, a->type);
    switch (a->type) {
    case ACL_SRC_IP:
    case ACL_DST_IP:
    case ACL_MY_IP:
	return aclDumpIpList(a->data);
    case ACL_SRC_DOMAIN:
    case ACL_DST_DOMAIN:
	return aclDumpDomainList(a->data);
#if SQUID_SNMP
    case ACL_SNMP_COMMUNITY:
	return wordlistDup((wordlist *)a->data);
#endif
#if USE_IDENT
    case ACL_IDENT:
	return aclDumpUserList((acl_user_data *)a->data);
    case ACL_IDENT_REGEX:
	return aclDumpRegexList((relist *)a->data);
#endif
    case ACL_PROXY_AUTH:
	return aclDumpUserList((acl_user_data *)a->data);
    case ACL_TIME:
	return aclDumpTimeSpecList((acl_time_data *)a->data);
    case ACL_PROXY_AUTH_REGEX:
    case ACL_URL_REGEX:
    case ACL_URLPATH_REGEX:
