    *head = A;
}

bool
ACL::valid () const
{
    return data != NULL;
}

void
ACL::parse()
{
    switch (aclType()) {

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

    case ACL_PROTO:
        aclParseProtoList(&data);
        break;

    case ACL_METHOD:
        aclParseMethodList(&data);
        break;

    case ACL_DERIVED:
        fatal ("overriden");
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

    case ACL_NONE:

    case ACL_ENUM_MAX:
        fatal("Bad ACL type");
        break;
    }
}

/* does name lookup, returns page_id */
err_type
aclGetDenyInfoPage(acl_deny_info_list ** head, const char *name)
