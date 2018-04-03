	}
	userdn = ldap_get_dn(ld, entry);
	if (!userdn) {
	    fprintf(stderr, "squid_ldap_auth: ERROR, could not get user DN for '%s'\n", userid);
	    ldap_msgfree(res);
	    return 1;
	}
	snprintf(dn, sizeof(dn), "%s", userdn);
	free(userdn);
	ldap_msgfree(res);
    } else {
	snprintf(dn, sizeof(dn), "uid=%s,%s", userid, basedn);
    }

    if (ldap_simple_bind_s(ld, dn, password) != LDAP_SUCCESS)
	return 1;
    
    return 0;
}