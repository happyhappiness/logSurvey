 static void
 squid_ldap_set_connect_timeout(LDAP * ld, int timelimit)
 {
-    fprintf(stderr, "Connect timeouts not supported in your LDAP library\n");
+    fprintf(stderr, "WARNING: Connect timeouts not supported in your LDAP library\n");
 }
 static void
 squid_ldap_memfree(char *p)
