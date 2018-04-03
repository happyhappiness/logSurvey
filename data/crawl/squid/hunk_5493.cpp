 	fprintf(stderr, "\t-R\t\t\tdo not follow referrals\n");
 	fprintf(stderr, "\t-a never|always|search|find\n\t\t\t\twhen to dereference aliases\n");
 	fprintf(stderr, "\t-v 1|2\t\t\tLDAP version\n");
-	fprintf(stderr, "\t-Z\t\t\tTLS encrypt the LDAP connection, requires LDAP version 3\n");
-	fprintf(stderr, "\t-g\t\t\tfirst query parameter is additional groups base RDN for this query\n");
+	fprintf(stderr, "\t-Z\t\t\tTLS encrypt the LDAP connection, requires\n\t\t\t\tLDAP version 3\n");
+	fprintf(stderr, "\t-g\t\t\tfirst query parameter is base DN extension\n\t\t\t\tfor this query\n");
+	fprintf(stderr, "\t-S\t\t\tStrip NT domain from usernames\n");
 	fprintf(stderr, "\n");
 	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");
 	exit(1);
     }
     while (fgets(buf, 256, stdin) != NULL) {
-	char *t;
+	char *tptr;
 	int found = 0;
-	user = strwordtok(buf, &t);
-	if (use_grouprdn)
-		grouprdn = strwordtok(NULL, &t);
+	user = strwordtok(buf, &tptr);
+	if (user && strip_nt_domain) {
+	    char *u = strchr(user, '\\');
+	    if (!u)
+		u = strchr(user, '/');
+	    if (u && u[1])
+		user = u + 1;
+	}
+	if (use_extension_dn)
+		extension_dn = strwordtok(NULL, &tptr);
 
-	tryagain = 1;
-	while (!found && user && (group = strwordtok(NULL, &t)) != NULL) {
+	while (!found && user && (group = strwordtok(NULL, &tptr)) != NULL) {
 
 	  recover:
 	    if (ld == NULL) {
