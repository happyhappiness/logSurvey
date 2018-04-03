	ldapServer = "localhost";

    if (!basedn || !searchfilter) {
	fprintf(stderr, "\n" PROGRAM_NAME " version " PROGRAM_VERSION "\n\n");
	fprintf(stderr, "Usage: " PROGRAM_NAME " -b basedn -f filter [options] ldap_server_name\n\n");
	fprintf(stderr, "\t-b basedn (REQUIRED)\tbase dn under where to search for groups\n");
	fprintf(stderr, "\t-f filter (REQUIRED)\tgroup search filter pattern. %%v = user,\n\t\t\t\t%%a = group\n");