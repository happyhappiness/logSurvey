	exit(1);
    }
    while (fgets(buf, 256, stdin) != NULL) {
	char *tptr;
	int found = 0;
	user = strwordtok(buf, &tptr);
	if (user && strip_nt_domain) {
	    char *u = strchr(user, '\\');
	    if (!u)
		u = strchr(user, '/');
	    if (u && u[1])
		user = u + 1;
	}
	if (use_extension_dn)
		extension_dn = strwordtok(NULL, &tptr);

	while (!found && user && (group = strwordtok(NULL, &tptr)) != NULL) {

	  recover:
	    if (ld == NULL) {
