    char *user, *passwd, *p;
    char *ldapServer;
    LDAP *ld;
    LDAPMessage *result, *e;

    setbuf(stdout, NULL);

    if (argc != 2) {
	fprintf(stderr, "Usage: squid_ldap_auth ldap_server_name\n");
	exit(1);
    }
    ldapServer = (char *) argv[1];
