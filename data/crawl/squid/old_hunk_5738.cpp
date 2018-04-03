	    (*acldata)->flags.strict = 1;
	} else {
	    (*acldata)->max = atoi(t);
	    debug(28, 5) ("aclParseUserMaxIP: Max IP address's %d\n", (*acldata)->max);
	}
    } else
	fatal("aclParseUserMaxIP: Malformed ACL %d\n");
