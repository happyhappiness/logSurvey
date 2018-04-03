 	ldapServer = "localhost";
 
     if (!basedn) {
-	fprintf(stderr, "Usage: squid_ldap_auth -b basedn [options] [ldap_server_name[:port]]...\n\n");
+	fprintf(stderr, "Usage: " PROGRAM_NAME " -b basedn [options] [ldap_server_name[:port]]...\n\n");
 	fprintf(stderr, "\t-b basedn (REQUIRED)\tbase dn under which to search\n");
 	fprintf(stderr, "\t-f filter\t\tsearch filter to locate user DN\n");
 	fprintf(stderr, "\t-u userattr\t\tusername DN attribute\n");
