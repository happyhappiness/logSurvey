    /* Main Loop */
    while (fgets (buf, BUFSIZE, stdin))
    {
	
	if ((p = strchr(buf, '\n')) != NULL)
	    *p = '\0';		/* strip \n */
	if ((p = strchr(buf, '\r')) != NULL)
	    *p = '\0';		/* strip \r */

	debug("Got '%s' from Squid (length: %d).\n",buf,sizeof(buf));
	
	username = strwordtok(buf, &t);
	group = strwordtok(NULL, &t);

	if (Valid_Group(username, group)) {
	    printf ("OK\n");
	} else {
	    printf ("ERR\n");
	}
    }
    return 0;
}
