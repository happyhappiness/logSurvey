    char *user, *passwd, *p;
    char *ldapServer;
    LDAP *ld;

    setbuf(stdout, NULL);

    while (argc > 2 && argv[1][0] == '-') {
	char *value;
	char option = argv[1][1];
	if (strlen(argv[1]) > 2) {
	    value = argv[1]+2;
	} else {
	    value = argv[2];
	    argv++;
	    argc--;
	}
	argv++;
	argc--;
	switch(option) {
	case 'b':
		basedn = value;
		break;
	case 'f':
		searchfilter = value;
		break;
	case 's':
		if (strcmp(value, "base") == 0)
		    searchscope = LDAP_SCOPE_BASE;
		else if (strcmp(value, "one") == 0)
		    searchscope = LDAP_SCOPE_ONELEVEL;
		else if (strcmp(value, "sub") == 0)
		    searchscope = LDAP_SCOPE_SUBTREE;
		else {
		    fprintf(stderr, "squid_ldap_auth: ERROR: Unknown search scope '%s'\n", value);
		    exit(1);
		}
		break;
	default:
		fprintf(stderr, "squid_ldap_auth: ERROR: Unknown command line option '%c'\n", option);
		exit(1);
	}
    }
	
    if (argc != 2) {
	fprintf(stderr, "Usage: squid_ldap_auth [-b basedn] [-s searchscope] [-f searchfilter] ldap_server_name\n");
	exit(1);
    }
    ldapServer = (char *) argv[1];
