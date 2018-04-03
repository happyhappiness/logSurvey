	    /* Authenticated and Authorised for this ACL */
	    return 1;
	case -2:
	case -1:
	    fatal("Invalid response from match routine\n");
	    break;
	}

	/* NOTREACHED */
#if SQUID_SNMP
    case ACL_SNMP_COMMUNITY:
