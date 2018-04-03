
	case 5:
	    if (m1 < 0 || m1 > 32) {
		fprintf(stderr,
		    "cached.conf error in IP acl line %s (ignored)\n",
		    ip_str);
		return;
	    }
