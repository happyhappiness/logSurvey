 	snprintf(dn, sizeof(dn), "%s=%s,%s", userattr, userid, basedn);
     }
 
+    if (debug)
+	fprintf(stderr, "attempting to bind to user '%s'\n", dn);
     if (ldap_simple_bind_s(ld, dn, password) != LDAP_SUCCESS)
 	return 1;
 
