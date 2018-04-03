}

wordlist *
ACL::dumpGeneric () const
{
    debug(28, 3) ("ACL::dumpGeneric: %s type %d\n", name, aclType());
    return dump();
}

wordlist *
ACL::dump() const
{
    switch (aclType()) {
    case ACL_SRC_DOMAIN:
    case ACL_DST_DOMAIN:
	return aclDumpDomainList(data);
#if SQUID_SNMP
    case ACL_SNMP_COMMUNITY:
	return wordlistDup((wordlist *)data);
#endif
#if USE_IDENT
    case ACL_IDENT_REGEX:
	return aclDumpRegexList((relist *)data);
#endif
#if USE_IDENT
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
