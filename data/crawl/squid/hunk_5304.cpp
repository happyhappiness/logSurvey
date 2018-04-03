 	if (binddn) {
 	    rc = ldap_simple_bind_s(ld, binddn, bindpasswd);
 	    if (rc != LDAP_SUCCESS) {
-		fprintf(stderr, "squid_ldap_auth: WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
+		fprintf(stderr, PROGRAM_NAME ": WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
 		return 1;
 	    }
 	}
