 	    }
 	    rfc1738_unescape(extension_dn);
 	}
-
 	while (!found && user && (group = strtok(NULL, " \n")) != NULL) {
 	    rfc1738_unescape(group);
 
 	  recover:
 	    if (ld == NULL) {
 #if HAS_URI_SUPPORT
-	    	if (strstr(ldapServer, "://") != NULL) {
-		    rc = ldap_initialize( &ld, ldapServer );
-		    if( rc != LDAP_SUCCESS ) {
+		if (strstr(ldapServer, "://") != NULL) {
+		    rc = ldap_initialize(&ld, ldapServer);
+		    if (rc != LDAP_SUCCESS) {
 			fprintf(stderr, "\nUnable to connect to LDAPURI:%s\n", ldapServer);
 			break;
 		    }
-	    	} else
+		} else
 #endif
 #if NETSCAPE_SSL
 		if (sslpath) {
-		    if ( !sslinit && (ldapssl_client_init(sslpath, NULL) != LDAP_SUCCESS)) {
+		    if (!sslinit && (ldapssl_client_init(sslpath, NULL) != LDAP_SUCCESS)) {
 			fprintf(stderr, "\nUnable to initialise SSL with cert path %s\n",
-				sslpath);
+			    sslpath);
 			exit(1);
 		    } else {
 			sslinit++;
 		    }
 		    if ((ld = ldapssl_init(ldapServer, port, 1)) == NULL) {
 			fprintf(stderr, "\nUnable to connect to SSL LDAP server: %s port:%d\n",
-				ldapServer, port);
+			    ldapServer, port);
 			exit(1);
 		    }
 		} else
 #endif
 		if ((ld = ldap_init(ldapServer, port)) == NULL) {
-		    fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",ldapServer, port);
+		    fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n", ldapServer, port);
 		    break;
 		}
-
 		if (connect_timeout)
 		    squid_ldap_set_connect_timeout(ld, connect_timeout);
 