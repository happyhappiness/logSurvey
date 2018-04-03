 	}
     }
 
-    if (!basedn || !searchfilter || argc != 2) {
-	fprintf(stderr, "Usage: squid_ldap_match [options] ldap_server_name\n\n");
+    while (argc > 1) {
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
+
+    if (!ldapServer)
+	ldapServer = "localhost";
+
+    if (!basedn || !searchfilter) {
+	fprintf(stderr, "Usage: squid_ldap_match -f basedn -f filter [options] ldap_server_name\n\n");
 	fprintf(stderr, "\t-b basedn (REQUIRED)\tbase dn under where to search\n");
-	fprintf(stderr, "\t-f filter (REQUIRED)\tsearch filter pattern\n");
+	fprintf(stderr, "\t-f filter (REQUIRED)\tsearch filter pattern. %v = user, %a = group\n");
 	fprintf(stderr, "\t-s base|one|sub\t\tsearch scope\n");
 	fprintf(stderr, "\t-D binddn\t\tDN to bind as to perform searches\n");
 	fprintf(stderr, "\t-w bindpasswd\t\tpassword for binddn\n");
-	fprintf(stderr, "\t-p\t\t\tpersistent LDAP connection\n");
+	fprintf(stderr, "\t-h server\t\tLDAP server (defaults to localhost)\n");
+	fprintf(stderr, "\t-p port\t\t\tLDAP server port (defaults to %d)\n", LDAP_PORT);
+	fprintf(stderr, "\t-P\t\t\tpersistent LDAP connection\n");
 	fprintf(stderr, "\t-R\t\t\tdo not follow referrals\n");
 	fprintf(stderr, "\t-a never|always|search|find\n\t\t\t\twhen to dereference aliases\n");
+	fprintf(stderr, "\t-v 1|2\t\t\tLDAP version\n");
+	fprintf(stderr, "\t-Z\t\t\tTLS encrypt the LDAP connection, requires LDAP version 3\n");
 	fprintf(stderr, "\n");
 	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");
 	exit(1);
     }
 
-    ldapServer = (char *) argv[1];
-
     while (fgets(buf, 256, stdin) != NULL) {
-	user = strtok(buf, " \n\r");
-	group = strtok(NULL, " \n\r");
-	grouprdn = strtok(NULL, " \n\r");
+	char *t;
+	user = strwordtok(buf, &t);
+	group = strwordtok(NULL, &t);
+	grouprdn = strwordtok(NULL, &t);
 
 	if (!user || !group) {
 	    printf("ERR\n");
