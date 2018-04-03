	return;
    }
    *acldata = cbdataAlloc(acl_user_ip_data);
    if ((t = strtokFile())) {
	debug(28, 5) ("aclParseUserMaxIP: First token is %s\n", t);
	if (strcmp("-s", t) == 0) {
	    debug(28, 5) ("aclParseUserMaxIP: Going strict\n");
	    (*acldata)->flags.strict = 1;
	} else {
	    (*acldata)->max = atoi(t);
	    debug(28, 5) ("aclParseUserMaxIP: Max IP address's %d\n", (int) (*acldata)->max);
	}
    } else
	fatal("aclParseUserMaxIP: Malformed ACL %d\n");
}

void