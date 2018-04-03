    case ACL_IDENT: 
#endif
    case ACL_DERIVED:
	fatal ("overriden");
	break;
#if SQUID_SNMP
    case ACL_SNMP_COMMUNITY:
