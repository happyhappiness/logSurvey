 	fprintf(stderr, "\t-s base|one|sub\t\tsearch scope\n");
 	fprintf(stderr, "\t-D binddn\t\tDN to bind as to perform searches\n");
 	fprintf(stderr, "\t-w bindpasswd\t\tpassword for binddn\n");
+	fprintf(stderr, "\t-W secretfile\t\tread password for binddn from file secretfile\n");
 #if HAS_URI_SUPPORT
 	fprintf(stderr, "\t-H URI\t\t\tLDAPURI (defaults to ldap://localhost)\n");
 #endif
