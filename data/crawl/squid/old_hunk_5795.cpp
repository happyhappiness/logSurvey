	}
	*passwd++ = '\0';	/* Cut in username,password */
	tryagain = 1;
recover:
	if (ld == NULL) {
	    if ((ld = ldap_init(ldapServer, LDAP_PORT)) == NULL) {
		fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
