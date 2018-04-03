    struct stat sb;
    time_t change_time = 0;
    char buf[256];
    char *user, *realm, *p;
    user_data *u;
    HASH HA1;
    HASHHEX HHA1;
    setbuf(stdout, NULL);
    if (argc != 2) {
	fprintf(stderr, "Usage: digest_pw_auth <passwordfile>\n");
	exit(1);
    }
    if (stat(argv[1], &sb) != 0) {
	fprintf(stderr, "cannot stat %s\n", argv[1]);
	exit(1);
    }
    while (fgets(buf, 256, stdin) != NULL) {
	if ((p = strchr(buf, '\n')) != NULL)
	    *p = '\0';		/* strip \n */
	if (stat(argv[1], &sb) == 0) {
	    if (sb.st_mtime != change_time) {
		read_passwd_file(argv[1]);
		change_time = sb.st_mtime;
	    }
	}
	if ((user = strtok(buf, "\"")) == NULL) {
	    printf("ERR\n");
	    continue;
