    }

    if (!ldapServer)
	ldapServer = (char *)"localhost";

    if (!basedn || !searchfilter) {
	fprintf(stderr, "\n" PROGRAM_NAME " version " PROGRAM_VERSION "\n\n");
