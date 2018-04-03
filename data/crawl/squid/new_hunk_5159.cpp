		    fprintf(stderr, PROGRAM_NAME ": WARNING, SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
		}
#endif
		ret = 1;
		goto search_done;
	    }
	}
	entry = ldap_first_entry(search_ld, res);
	if (!entry) {
	    ret = 1;
	    goto search_done;
	}
	userdn = ldap_get_dn(search_ld, entry);
	if (!userdn) {
	    fprintf(stderr, PROGRAM_NAME ": ERROR, could not get user DN for '%s'\n", userid);
	    ret = 1;
	    goto search_done;
	}
	snprintf(dn, sizeof(dn), "%s", userdn);
	squid_ldap_memfree(userdn);

	if (ret == 0 && (!bind_once || passwdattr)) {
	    /* Reuse the search connection for comparing the user password attribute */
	    bind_ld = search_ld;
	    search_ld = NULL;
	}
      search_done:
	if (res) {
	    ldap_msgfree(res);
	    res = NULL;
	}
	if (search_ld != persistent_ld) {
	    ldap_unbind(search_ld);
	    search_ld = NULL;
	}
	if (ret != 0)
	    return ret;
    } else {
	snprintf(dn, sizeof(dn), "%s=%s,%s", userattr, userid, basedn);
    }

    if (debug)
	fprintf(stderr, "attempting to bind to user '%s'\n", dn);
    if (!bind_ld && !bind_once)
	bind_ld = persistent_ld;
    if (!bind_ld)
	bind_ld = open_ldap_connection(ldapServer, port);
    if (passwdattr && ldap_compare_s(bind_ld, dn, passwdattr, password) != LDAP_COMPARE_TRUE)
	ret = 1;
    else if (ldap_simple_bind_s(bind_ld, dn, password) != LDAP_SUCCESS)
	ret = 1;
    if (bind_ld != persistent_ld) {
	ldap_unbind(bind_ld);
	bind_ld = NULL;
    }
    return 0;
}

int 
readSecret(const char *filename)
{
    char buf[BUFSIZ];
    char *e = NULL;
    FILE *f;
    char *passwd = NULL;

    if (!(f = fopen(filename, "r"))) {
	fprintf(stderr, PROGRAM_NAME " ERROR: Can not read secret file %s\n", filename);
	return 1;
    }
    if (!fgets(buf, sizeof(buf) - 1, f)) {
	fprintf(stderr, PROGRAM_NAME " ERROR: Secret file %s is empty\n", filename);
	fclose(f);
	return 1;
    }
    /* strip whitespaces on end */
    if ((e = strrchr(buf, '\n')))
	*e = 0;
    if ((e = strrchr(buf, '\r')))
	*e = 0;

    passwd = (char *) calloc(sizeof(char), strlen(buf) + 1);
    if (!passwd) {
	fprintf(stderr, PROGRAM_NAME " ERROR: can not allocate memory\n");
	exit(1);
    }
    strcpy(passwd, buf);
    bindpasswd = passwd;

    fclose(f);

    return 0;
}
