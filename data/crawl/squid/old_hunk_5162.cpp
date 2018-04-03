    }
    if (!passwdfile) {
        fprintf(stderr, "Usage: digest_pw_auth [OPTIONS] <passwordfile>\n");
        fprintf(stderr, "  -c   accept HHA1 passwords rather than plaintext in passwordfile\n");
	exit(1);
    }
    if (stat(passwdfile, &sb) != 0) {
