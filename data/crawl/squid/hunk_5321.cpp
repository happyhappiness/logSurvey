 
 	  recover:
 	    if (ld == NULL) {
+#if HAS_URI_SUPPORT
+	    	if (strstr(ldapServer, "://") != NULL) {
+		    rc = ldap_initialize( &ld, ldapServer );
+		    if( rc != LDAP_SUCCESS ) {
+			fprintf(stderr, "\nUnable to connect to LDAPURI:%s\n", ldapServer);
+			break;
+		    }
+	    	} else
+#endif
 		if ((ld = ldap_init(ldapServer, port)) == NULL) {
-		    fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
-			ldapServer, port);
+		    fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",ldapServer, port);
 		    break;
 		}
+
 #ifdef LDAP_VERSION3
 		if (version == -1) {
 		    version = LDAP_VERSION2;
