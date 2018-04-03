
    /* get user options */
    while ((ch = getopt(argc, argv, "spg:")) != -1) {
  	switch (ch) {
	case 's':
	    strip_dm = 1;
	    break;
	case 'p':
	    check_pw = 1;
	    break;
	case 'g':
	    grents[i] = calloc(strlen(optarg) + 1, sizeof(char));
	    strcpy(grents[i], optarg);
	    if (i < MAX_GROUP) {
		i++;
	    } else {
		fprintf(stderr,
		    "Exceeded maximum number of allowed groups (%i)\n", i);
		exit(1);
	    }
	    break;
	case '?':
	    if (xisprint(optopt)) {

		fprintf(stderr, "Unknown option '-%c'.\n", optopt);
	    } else {
		fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
	    }

	default:
	    usage(argv[0]);
	    exit(1);
	}
    }
    if (optind < argc) {
	fprintf(stderr, "Unknown option '%s'\n", argv[optind]);
	usage(argv[0]);
	exit(1);
    }
    while (fgets(buf, sizeof(buf), stdin)) {
	j = 0;
	if ((p = strchr(buf, '\n')) == NULL) {
	    /* too large message received.. skip and deny */
	    fprintf(stderr, "%s: ERROR: Too large: %s\n", argv[0], buf);
	    while (fgets(buf, sizeof(buf), stdin)) {
		fprintf(stderr, "%s: ERROR: Too large..: %s\n", argv[0], buf);
		if (strchr(buf, '\n') != NULL)
		    break;
	    }
	    goto error;
	}
	*p = '\0';
	if ((p = strtok(buf, " ")) == NULL) {
	    goto error;
	} else {
	    user = p;
	    rfc1738_unescape(user);
	    if (user && strip_dm) {
		suser = strchr(user, '\\');
		if (!suser) suser = strchr(user, '/');
		if (suser && suser[1]) user = suser + 1;
	    }
	    /* check groups supplied by Squid */
	    while ((p = strtok(NULL, " ")) != NULL) {
		rfc1738_unescape(p);
		if (check_pw == 1)
		    j += validate_user_pw(user, p);

		j += validate_user_gr(user, p);
	    }
	}

	/* check groups supplied on the command line */
	for (i = 0; grents[i] != NULL; i++) {
	    if (check_pw == 1) {
		j += validate_user_pw(user, grents[i]);
	    }
	    j += validate_user_gr(user, grents[i]);
	}

	if (j > 0) {
	    printf("OK\n");
	} else {
error:
	    printf("ERR\n");
	}
    }
    return 0;
}
