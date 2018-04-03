	    else if (strcmp(value, "find") == 0)
		aliasderef = LDAP_DEREF_FINDING;
	    else {
		fprintf(stderr, "squid_ldap_auth: ERROR: Unknown alias dereference method '%s'\n", value);
		exit(1);
	    }
	    break;
