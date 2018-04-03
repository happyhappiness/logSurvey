	snprintf(dn, sizeof(dn), "%s=%s,%s", userattr, userid, basedn);
    }

    if (ldap_simple_bind_s(ld, dn, password) != LDAP_SUCCESS)
	return 1;

