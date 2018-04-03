 	fprintf(stderr, "\t-R\t\t\tdo not follow referrals\n");
 	fprintf(stderr, "\t-a never|always|search|find\n\t\t\t\twhen to dereference aliases\n");
 	fprintf(stderr, "\t-v 1|2\t\t\tLDAP version\n");
-	fprintf(stderr, "\t-Z\t\t\TLS encrypt the LDAP connection, requires LDAP version 3\n");
+	fprintf(stderr, "\t-Z\t\t\tTLS encrypt the LDAP connection, requires LDAP version 3\n");
 	fprintf(stderr, "\n");
 	fprintf(stderr, "\tIf no search filter is specified, then the dn <userattr>=user,basedn\n\twill be used (same as specifying a search filter of '<userattr>=',\n\tbut quicker as as there is no need to search for the user DN)\n\n");
 	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");