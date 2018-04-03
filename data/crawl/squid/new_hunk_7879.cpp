	    break;

	default:
	    debug(3, 0, "addToIPACL: Ignoring invalid IP acl line '%s'\n",
		ip_str);
	    return;
	}
    }
