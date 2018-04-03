    char *ch2, *decoded, *cred;
    int plen;

    if (fgets(buf, BUFFER_SIZE, stdin) == NULL)
	exit(0);		/* BIIG buffer */
    ch2 = memchr(buf, '\n', BUFFER_SIZE);	/* safer against overrun than strchr */
    if (ch2) {
	*ch2 = '\0';		/* terminate the string at newline. */
