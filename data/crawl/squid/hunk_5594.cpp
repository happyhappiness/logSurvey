 	tryagain = 1;
 recover:
 	if (ld == NULL) {
-	    if ((ld = ldap_init(ldapServer, LDAP_PORT)) == NULL) {
+	    if ((ld = ldap_init(ldapServer, port)) == NULL) {
 		fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
-		    ldapServer, LDAP_PORT);
-		exit(1);
+		    ldapServer, port);
+		printf("ERR\n");
+		continue;
+	    }
+	    if (version == -1 ) {
+		version = LDAP_VERSION2;
+	    }
+
+	    if( ldap_set_option( ld, LDAP_OPT_PROTOCOL_VERSION, &version )
+		    != LDAP_OPT_SUCCESS )
+	    {
+		fprintf( stderr, "Could not set LDAP_OPT_PROTOCOL_VERSION %d\n",
+			version );
+	        ldap_unbind(ld);
+		printf("ERR\n");
+		continue;
 	    }
+
+	    if ( use_tls && ( version == LDAP_VERSION3 ) && ( ldap_start_tls_s( ld, NULL, NULL ) == LDAP_SUCCESS )) {
+		fprintf( stderr, "Could not Activate TLS connection\n");
+	        ldap_unbind(ld);
+		printf("ERR\n");
+		continue;
+	    }
+	    
 	    squid_ldap_set_referrals(ld, !noreferrals);
 	    squid_ldap_set_aliasderef(ld, aliasderef);
 	}
 	rc = ldap_simple_bind_s(ld, binddn, bindpasswd);
 	if (rc != LDAP_SUCCESS) {
 	    fprintf(stderr, "squid_ldap_match: WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
-	    exit(1);
+	    ldap_unbind(ld);
+	    printf("ERR\n");
+	    continue;
 	}
 	if (debug) printf("Binding OK\n");
 	if (searchLDAP(ld, group, user, grouprdn) != 0) {