    }

    if (!ldapServer)
	ldapServer = "localhost";

    if (!userbasedn || !((passattr != NULL) || (edir_universal_passwd && usersearchfilter && version == LDAP_VERSION3 && use_tls))) {
	fprintf(stderr, "Usage: " PROGRAM_NAME " -b basedn -f filter [options] ldap_server_name\n\n");
