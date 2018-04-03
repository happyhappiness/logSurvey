
	case 5:
	    if (m1 < 0 || m1 > 32) {
		debug(3, 0, "addToIPACL: Ignoring invalid IP acl line '%s'\n",
		    ip_str);
		return;
	    }
