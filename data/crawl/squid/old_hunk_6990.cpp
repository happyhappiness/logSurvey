	    break;
	case ACL_NONE:
	default:
	    fatal_dump("aclDestroyAcls: Found ACL_NONE?");
	    break;
	}
	safe_free(a->cfgline);
