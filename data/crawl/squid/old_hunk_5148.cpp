	usage(argv[0]);
	exit(1);
    }
    while (fgets(buf, BUFSIZE, stdin)) {
	j = 0;
	if ((p = strchr(buf, '\n')) != NULL) {
	    *p = '\0';
	} else {
	    /* too large message received.. skip and deny */
	    fprintf(stderr, "%s: ERROR: Too large: %s\n", argv[0], buf);
	    while (fgets(buf, BUFSIZE, stdin)) {
		fprintf(stderr, "%s: ERROR: Too large..: %s\n", argv[0], buf);
		if (strchr(buf, '\n') != NULL)
		    break;
	    }
	    goto error;
	}
	if ((p = strwordtok(buf, &t)) == NULL) {
	    goto error;
	} else {
	    user = p;
	    /* check groups supplied by Squid */
	    while ((p = strwordtok(NULL, &t)) != NULL) {
		if (check_pw == 1)
		    j += validate_user_pw(user, p);

