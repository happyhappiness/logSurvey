 	rfc1738_unescape(passwd);
 	tryagain = 1;
       recover:
-	if (ld == NULL) {
-#if HAS_URI_SUPPORT
-	    if (strstr(ldapServer, "://") != NULL) {
-		int rc = ldap_initialize( &ld, ldapServer );
-		if( rc != LDAP_SUCCESS ) {
-		    fprintf(stderr, "\nUnable to connect to LDAPURI:%s\n", ldapServer);
-		    break;
-		}
-	    } else
-#endif
-#if NETSCAPE_SSL
-	    if (sslpath) {
-		if ( !sslinit && (ldapssl_client_init(sslpath, NULL) != LDAP_SUCCESS)) {
-		    fprintf(stderr, "\nUnable to initialise SSL with cert path %s\n",
-			    sslpath);
-		    exit(1);
-		} else {
-		    sslinit++;
-		}
-		if ((ld = ldapssl_init(ldapServer, port, 1)) == NULL) {
-		    fprintf(stderr, "\nUnable to connect to SSL LDAP server: %s port:%d\n",
-			    ldapServer, port);
-		    exit(1);
-		}
-	    } else
-#endif
-	    if ((ld = ldap_init(ldapServer, port)) == NULL) {
-		fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
-		    ldapServer, port);
-		exit(1);
-	    }
-
-	    if (connect_timeout)
-		squid_ldap_set_connect_timeout(ld, connect_timeout);
-
-#ifdef LDAP_VERSION3
-	    if (version == -1 ) {
-                version = LDAP_VERSION2;
-	    }
-
-	    if( ldap_set_option( ld, LDAP_OPT_PROTOCOL_VERSION, &version )
-		    != LDAP_OPT_SUCCESS )
-	    {
-                fprintf( stderr, "Could not set LDAP_OPT_PROTOCOL_VERSION %d\n",
-                        version );
-                exit(1);
-	    }
-
-	    if ( use_tls && ( version == LDAP_VERSION3 ) && ( ldap_start_tls_s( ld, NULL, NULL ) != LDAP_SUCCESS )) {
-                fprintf( stderr, "Could not Activate TLS connection\n");
-                exit(1);
-	    }
-#endif
-	    squid_ldap_set_timelimit(ld, timelimit);
-	    squid_ldap_set_referrals(ld, !noreferrals);
-	    squid_ldap_set_aliasderef(ld, aliasderef);
-	}
-	if (checkLDAP(ld, user, passwd) != 0) {
+	if (ld == NULL && persistent)
+	    ld = open_ldap_connection(ldapServer, port);
+	if (checkLDAP(ld, user, passwd, ldapServer, port) != 0) {
 	    if (tryagain && squid_ldap_errno(ld) != LDAP_INVALID_CREDENTIALS) {
 		tryagain = 0;
 		ldap_unbind(ld);
