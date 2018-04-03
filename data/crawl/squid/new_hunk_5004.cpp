    }

    if (debug)
	fprintf(stderr, "attempting to authenticate user '%s'\n", dn);
    if (!bind_ld && !bind_once)
	bind_ld = persistent_ld;
    if (!bind_ld)
	bind_ld = open_ldap_connection(ldapServer, port);
    if (passwdattr) {
	if (ldap_compare_s(bind_ld, dn, passwdattr, password) != LDAP_COMPARE_TRUE) {
	    ret = 1;
	}
    } else if (ldap_simple_bind_s(bind_ld, dn, password) != LDAP_SUCCESS)
	ret = 1;
    if (bind_ld != persistent_ld) {
	ldap_unbind(bind_ld);