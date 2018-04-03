    struct stat sb;
    time_t change_time = 0;
    char buf[256];
    char *user, *realm, *p, *passwdfile=NULL;
    user_data *u;
    HASH HA1;
    HASHHEX HHA1;
    int ha1mode=0;

    setbuf(stdout, NULL);
    if(argc == 2){
        passwdfile = argv[1];
    }
    if((argc == 3) && !strcmp("-c", argv[1])){
        ha1mode=1;
        passwdfile = argv[2];
    }
    if (!passwdfile) {
        fprintf(stderr, "Usage: digest_pw_auth [OPTIONS] <passwordfile>\n");
        fprintf(stderr, "  -c   accept HHA1 passwords rather than plaintext in passwordfile\n");
	exit(1);
    }
    if (stat(passwdfile, &sb) != 0) {
	fprintf(stderr, "cannot stat %s\n", passwdfile);
	exit(1);
    }
    while (fgets(buf, 256, stdin) != NULL) {
	if ((p = strchr(buf, '\n')) != NULL)
	    *p = '\0';		/* strip \n */
	if (stat(passwdfile, &sb) == 0) {
	    if (sb.st_mtime != change_time) {
		read_passwd_file(passwdfile, ha1mode);
		change_time = sb.st_mtime;
	    }
	}
	if (!hash) {
	    printf("ERR\n");
	    continue;
	}
	if ((user = strtok(buf, "\"")) == NULL) {
	    printf("ERR\n");
	    continue;
