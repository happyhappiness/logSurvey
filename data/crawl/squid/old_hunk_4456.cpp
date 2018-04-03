	    ldap_unbind(ld);
	    ld = NULL;
	}
	if (use_tls && (version == LDAP_VERSION3) && (ldap_start_tls_s(ld, NULL, NULL) == LDAP_SUCCESS)) {
	    fprintf(stderr, "Could not Activate TLS connection\n");
	    ldap_unbind(ld);
	    ld = NULL;
	}
#endif
	squid_ldap_set_timelimit(timelimit);