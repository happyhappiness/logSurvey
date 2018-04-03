	rfc1738_unescape(passwd);
	tryagain = 1;
      recover:
	if (ld == NULL && persistent)
	    ld = open_ldap_connection(ldapServer, port);
	if (checkLDAP(ld, user, passwd, ldapServer, port) != 0) {
	    if (tryagain && squid_ldap_errno(ld) != LDAP_INVALID_CREDENTIALS) {
		tryagain = 0;
		ldap_unbind(ld);
