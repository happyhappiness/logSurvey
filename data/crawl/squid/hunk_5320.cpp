 	fprintf(stderr, "\t-s base|one|sub\t\tsearch scope\n");
 	fprintf(stderr, "\t-D binddn\t\tDN to bind as to perform searches\n");
 	fprintf(stderr, "\t-w bindpasswd\t\tpassword for binddn\n");
+#if HAS_URI_SUPPORT
+	fprintf(stderr, "\t-H URI\t\t\tLDAPURI (defaults to ldap://localhost)\n");
+#endif
 	fprintf(stderr, "\t-h server\t\tLDAP server (defaults to localhost)\n");
 	fprintf(stderr, "\t-p port\t\t\tLDAP server port (defaults to %d)\n", LDAP_PORT);
 	fprintf(stderr, "\t-P\t\t\tpersistent LDAP connection\n");
 	fprintf(stderr, "\t-R\t\t\tdo not follow referrals\n");
 	fprintf(stderr, "\t-a never|always|search|find\n\t\t\t\twhen to dereference aliases\n");
-	fprintf(stderr, "\t-v 1|2\t\t\tLDAP version\n");
+#ifdef LDAP_VERSION3
+	fprintf(stderr, "\t-v 2|3\t\t\tLDAP version\n");
 	fprintf(stderr, "\t-Z\t\t\tTLS encrypt the LDAP connection, requires\n\t\t\t\tLDAP version 3\n");
+#endif
 	fprintf(stderr, "\t-g\t\t\tfirst query parameter is base DN extension\n\t\t\t\tfor this query\n");
 	fprintf(stderr, "\t-S\t\t\tStrip NT domain from usernames\n");
 	fprintf(stderr, "\n");
