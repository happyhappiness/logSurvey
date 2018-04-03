    }

    if (debug)
	fprintf(stderr, "filter %s\n", filter);

    rc = ldap_search_s(ld, searchbase, searchscope, filter, NULL, 1, &res);
    if (rc != LDAP_SUCCESS) {
