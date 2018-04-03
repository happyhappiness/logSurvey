 	ldapServer = "localhost";
 
     if (!basedn || !searchfilter) {
-	fprintf(stderr, "Usage: squid_ldap_match -f basedn -f filter [options] ldap_server_name\n\n");
+	fprintf(stderr, "Usage: squid_ldap_match -b basedn -f filter [options] ldap_server_name\n\n");
 	fprintf(stderr, "\t-b basedn (REQUIRED)\tbase dn under where to search\n");
 	fprintf(stderr, "\t-f filter (REQUIRED)\tsearch filter pattern. %%v = user, %%a = group\n");
 	fprintf(stderr, "\t-s base|one|sub\t\tsearch scope\n");