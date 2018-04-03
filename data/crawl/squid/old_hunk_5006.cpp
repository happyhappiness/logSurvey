    }
    if (use_tls) {
#ifdef LDAP_OPT_X_TLS
        if (version == LDAP_VERSION3 && ldap_start_tls_s(ld, NULL, NULL) != LDAP_SUCCESS) {
	    fprintf(stderr, "Could not Activate TLS connection\n");
	    exit(1);
	} else {
	    fprintf(stderr, "TLS requires LDAP version 3\n");
	    exit(1);
	}
#else
	fprintf(stderr, "TLS not supported with your LDAP library\n");
