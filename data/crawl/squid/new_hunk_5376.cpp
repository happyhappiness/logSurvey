{
    switch (aclType()) {
#if SQUID_SNMP

    case ACL_SNMP_COMMUNITY:
        return wordlistDup((wordlist *)data);
#endif

    case ACL_DERIVED:
        fatal ("unused");

    case ACL_REP_MIME_TYPE:
        return aclDumpRegexList((relist *)data);

    case ACL_SRC_ASN:

    case ACL_MAXCONN:

    case ACL_DST_ASN:
        return aclDumpIntlistList((intlist *)data);

    case ACL_MAX_USER_IP:
        return aclDumpUserMaxIP(data);

    case ACL_URL_PORT:

    case ACL_MY_PORT:
        return aclDumpIntRangeList((intrange *)data);

    case ACL_PROTO:
        return aclDumpProtoList((intlist *)data);

    case ACL_METHOD:
        return aclDumpMethodList((intlist *)data);
#if USE_ARP_ACL

    case ACL_SRC_ARP:
        return aclDumpArpList(data);
#endif

    case ACL_EXTERNAL:
        return aclDumpExternal(data);

    case ACL_NONE:

    case ACL_ENUM_MAX:
        break;
    }

    debug(28, 1) ("ACL::dumpGeneric: no case for ACL type %d\n", aclType());
    return NULL;
}
