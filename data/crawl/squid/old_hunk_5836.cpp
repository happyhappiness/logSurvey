	fprintf(stderr, "\t-D binddn\t\tDN to bind as to perform searches\n");
	fprintf(stderr, "\t-w bindpasswd\t\tpassword for binddn\n");
	fprintf(stderr, "\t-p\t\t\tpersistent LDAP connection\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "\tIf no search filter is specified, then the dn uid=user,basedn will\n\tbe used (same as specifying a search filter of 'uid=', but quicker\n\tas as there is no need to search for the user DN)\n\n");
	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");