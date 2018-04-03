 	}
     }
 
-    if (!basedn || argc != 2) {
-	fprintf(stderr, "Usage: squid_ldap_auth [options] ldap_server_name\n\n");
+    while (argc > 1 && argv[1][0] == '-') {
+	char *value = argv[1];
+	if (ldapServer) {
+	    int len = strlen(ldapServer) + 1 + strlen(value) + 1;
+	    char *newhost = malloc(len);
+	    snprintf(newhost, len, "%s %s", ldapServer, value);
+	    free(ldapServer);
+	    ldapServer = newhost;
+	} else {
+	    ldapServer = strdup(value);
+	}
+	argc--;
+	argv++;
+    }
+    if (!ldapServer)
+	ldapServer = "localhost";
+
+    if (!basedn) {
+	fprintf(stderr, "Usage: squid_ldap_auth -b basedn [options] [ldap_server_name[:port]]...\n\n");
 	fprintf(stderr, "\t-b basedn (REQUIRED)\tbase dn under which to search\n");
 	fprintf(stderr, "\t-f filter\t\tsearch filter to locate user DN\n");
 	fprintf(stderr, "\t-u userattr\t\tusername DN attribute\n");
 	fprintf(stderr, "\t-s base|one|sub\t\tsearch scope\n");
 	fprintf(stderr, "\t-D binddn\t\tDN to bind as to perform searches\n");
 	fprintf(stderr, "\t-w bindpasswd\t\tpassword for binddn\n");
-	fprintf(stderr, "\t-p\t\t\tpersistent LDAP connection\n");
+	fprintf(stderr, "\t-h server\t\tLDAP server (defaults to localhost)\n");
+	fprintf(stderr, "\t-p port\t\tLDAP server port\n");
+	fprintf(stderr, "\t-P\t\t\tpersistent LDAP connection\n");
 	fprintf(stderr, "\t-R\t\t\tdo not follow referrals\n");
 	fprintf(stderr, "\t-a never|always|search|find\n\t\t\t\twhen to dereference aliases\n");
 	fprintf(stderr, "\n");
 	fprintf(stderr, "\tIf no search filter is specified, then the dn <userattr>=user,basedn\n\twill be used (same as specifying a search filter of '<userattr>=',\n\tbut quicker as as there is no need to search for the user DN)\n\n");
 	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");
 	exit(1);
     }
-    ldapServer = (char *) argv[1];
 
     while (fgets(buf, 256, stdin) != NULL) {
 	user = strtok(buf, " \r\n");