    char searchbase[8192];
    int rc = -1;
    if (ld) {
	if (usersearchfilter) {
	    char escaped_login[1024];
	    snprintf(searchbase, sizeof(searchbase), "%s", userbasedn);
	    ldap_escape_value(escaped_login, sizeof(escaped_login), login);
	    snprintf(filter, sizeof(filter), usersearchfilter, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login);

	  retrysrch:
	    if (debug)
		fprintf(stderr, "user filter '%s', searchbase '%s'\n", filter, searchbase);

	    rc = ldap_search_s(ld, searchbase, searchscope, filter, NULL, 0, &res);
	    if (rc != LDAP_SUCCESS) {
		if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
		    /* Everything is fine. This is expected when referrals
		     * are disabled.
		     */
		    rc = LDAP_SUCCESS;
		} else {
		    fprintf(stderr, PROGRAM_NAME " WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
#if defined(NETSCAPE_SSL)
		    if (sslpath && ((rc == LDAP_SERVER_DOWN) || (rc == LDAP_CONNECT_ERROR))) {
			int sslerr = PORT_GetError();
			fprintf(stderr, PROGRAM_NAME ": WARNING, SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
		    }
#endif
		    fprintf(stderr, PROGRAM_NAME " WARNING, LDAP search error, trying to recover'%s'\n", ldap_err2string(rc));
		    ldap_msgfree(res);
		    /* try to connect to the LDAP server agin, maybe my persisten conexion failed. */
		    if (!retry) {
			retry++;
			ldap_unbind(ld);
			ld = NULL;
			ldapconnect();
			goto retrysrch;
		    }
		    return NULL;

		}
	    }
	} else if (userdnattr) {
	    sprintf(searchbase, "%s=%s, %s", userdnattr, login, userbasedn);

	  retrydnattr:
	    if (debug)
		fprintf(stderr, "searchbase '%s'\n", searchbase);
	    rc = ldap_search_s(ld, searchbase, searchscope, NULL, NULL, 0, &res);
	}
	if (rc == LDAP_SUCCESS) {
	    entry = ldap_first_entry(ld, res);
	    if (entry)
		values = ldap_get_values(ld, entry, passattr);
	    else {
		ldap_msgfree(res);
		return NULL;
	    }
	    if (!values) {
		if (debug)
		    printf("No attribute value found\n");
		ldap_msgfree(res);
		return NULL;
	    }
	    value = values;
	    while (*value) {
		if (encrpass) {
		    if (strcmp(strtok(*value, delimiter), realm) == 0) {
			password = strtok(NULL, delimiter);
			break;
		    }
		} else {
		    password = *value;
		    break;
		}
		value++;
	    }
	    if (debug)
		printf("password: %s\n", password);
	    if (password)
		password = strdup(password);
	    ldap_value_free(values);
	    ldap_msgfree(res);
	    return password;
	} else {
	    fprintf(stderr, PROGRAM_NAME " WARNING, LDAP error '%s'\n", ldap_err2string(rc));
	    /* try to connect to the LDAP server agin, maybe my persisten conexion failed. */
	    if (!retry) {
		retry++;
		ldap_unbind(ld);
		ld = NULL;
		ldapconnect();
		goto retrydnattr;
	    }
	    return NULL;
	}
    }
    return NULL;
}