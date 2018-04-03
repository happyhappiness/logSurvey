	fprintf(stderr, "\t-R\t\t\tdo not follow referrals\n");
	fprintf(stderr, "\t-a never|always|search|find\n\t\t\t\twhen to dereference aliases\n");
	fprintf(stderr, "\t-v 1|2\t\t\tLDAP version\n");
	fprintf(stderr, "\t-Z\t\t\tTLS encrypt the LDAP connection, requires LDAP version 3\n");
	fprintf(stderr, "\t-g\t\t\tfirst query parameter is additional groups base RDN for this query\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");
	exit(1);
    }
    while (fgets(buf, 256, stdin) != NULL) {
	char *t;
	int found = 0;
	user = strwordtok(buf, &t);
	if (use_grouprdn)
		grouprdn = strwordtok(NULL, &t);

	tryagain = 1;
	while (!found && user && (group = strwordtok(NULL, &t)) != NULL) {

	  recover:
	    if (ld == NULL) {