	if (ld == NULL) {
#if HAS_URI_SUPPORT
	    if (strstr(ldapServer, "://") != NULL) {
		rc = ldap_initialize( &ld, ldapServer );
		if( rc != LDAP_SUCCESS ) {
		    fprintf(stderr, "\nUnable to connect to LDAPURI:%s\n", ldapServer);
		    break;
		}
	    } else
#endif
	    if ((ld = ldap_init(ldapServer, port)) == NULL) {
		fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
		    ldapServer, port);
		exit(1);
	    }
	}

        if (version == -1 ) {
                version = LDAP_VERSION2;
        }

        if( ldap_set_option( ld, LDAP_OPT_PROTOCOL_VERSION, &version )
                != LDAP_OPT_SUCCESS )
        {
                fprintf( stderr, "Could not set LDAP_OPT_PROTOCOL_VERSION %d\n",
                        version );
                exit(1);
        }

        if ( use_tls && ( version == LDAP_VERSION3 ) && ( ldap_start_tls_s( ld, NULL, NULL ) == LDAP_SUCCESS )) {
                fprintf( stderr, "Could not Activate TLS connection\n");
                exit(1);
        }

	    squid_ldap_set_referrals(ld, !noreferrals);
	    squid_ldap_set_aliasderef(ld, aliasderef);
	}
