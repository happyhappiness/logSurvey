    process_options(argc, argv);

    if (use_global) {
        if ((machinedomain = GetDomainName()) == NULL) {
	    fprintf(stderr, "%s Can't read machine domain\n", myname);
	    exit(1);
	}
	strlwr(machinedomain);
        if (!DefaultDomain)
            DefaultDomain = xstrdup(machinedomain);
    }

    debug("External ACL win32 group helper build " __DATE__ ", " __TIME__
    " starting up...\n");
    if (use_global)
        debug("Domain Global group mode enabled using '%s' as default domain.\n", DefaultDomain);
    if (use_case_insensitive_compare)
        debug("Warning: running in case insensitive mode !!!\n");
    if (use_PDC_only)
        debug("Warning: using only PDCs for group validation !!!\n");

    /* Main Loop */
    while (fgets (buf, sizeof(buf), stdin))
    {
	if (NULL == strchr(buf, '\n')) {
	    /* too large message received.. skip and deny */
	    fprintf(stderr, "%s: ERROR: Too large: %s\n", argv[0], buf);
