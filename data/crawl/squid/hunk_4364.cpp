 	if (found)
 	    printf("OK\n");
 	else {
-error:
+	  error:
 	    printf("ERR\n");
-}
+	}
 
 	if (ld != NULL) {
 	    if (!persistent || (squid_ldap_errno(ld) != LDAP_SUCCESS && squid_ldap_errno(ld) != LDAP_INVALID_CREDENTIALS)) {