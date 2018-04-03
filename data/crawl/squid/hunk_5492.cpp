 	ldapServer = "localhost";
 
     if (!basedn || !searchfilter) {
-	fprintf(stderr, "Usage: squid_ldap_match -b basedn -f filter [options] ldap_server_name\n\n");
-	fprintf(stderr, "\t-b basedn (REQUIRED)\tbase dn under where to search\n");
-	fprintf(stderr, "\t-f filter (REQUIRED)\tsearch filter pattern. %%v = user, %%a = group\n");
+	fprintf(stderr, "Usage: " PROGRAM_NAME " -b basedn -f filter [options] ldap_server_name\n\n");
+	fprintf(stderr, "\t-b basedn (REQUIRED)\tbase dn under where to search for groups\n");
+	fprintf(stderr, "\t-f filter (REQUIRED)\tgroup search filter pattern. %%v = user,\n\t\t\t\t%%a = group\n");
+	fprintf(stderr, "\t-B basedn (REQUIRED)\tbase dn under where to search for users\n");
+	fprintf(stderr, "\t-F filter (REQUIRED)\tuser search filter pattern. %%s = login\n");
 	fprintf(stderr, "\t-s base|one|sub\t\tsearch scope\n");
 	fprintf(stderr, "\t-D binddn\t\tDN to bind as to perform searches\n");
 	fprintf(stderr, "\t-w bindpasswd\t\tpassword for binddn\n");
