	tryagain = 1;
      recover:
	if (ld == NULL) {
	    if ((ld = ldap_init(ldapServer, port)) == NULL) {
		fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
		    ldapServer, port);
		exit(1);
	    }

        if (version == -1 ) {
                version = LDAP_VERSION2;