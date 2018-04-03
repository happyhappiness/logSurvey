    init_args(&margs);

    while (-1 != (opt = getopt(argc, argv, "diasg:D:N:u:U:t:T:p:l:b:m:h"))) {
	switch (opt) {
	case 'd':
	    debug_enabled = 1;
	    break;
	case 'i':
	    log_enabled = 1;
	    break;
	case 'a':
	    margs.rc_allow = 1;
	    break;
	case 's':
	    margs.ssl = (char *) "yes";
	    break;
	case 'g':
	    margs.glist = xstrdup(optarg);
	    break;
	case 'D':
	    margs.ddomain = xstrdup(optarg);
	    break;
	case 'N':
	    margs.nlist = xstrdup(optarg);
	    break;
	case 'u':
	    margs.luser = xstrdup(optarg);
	    break;
	case 'U':
	    margs.ulist = xstrdup(optarg);
	    break;
	case 't':
	    margs.ulist = xstrdup(optarg);
	    break;
	case 'T':
	    margs.tlist = xstrdup(optarg);
	    break;
	case 'p':
	    margs.lpass = xstrdup(optarg);
	    /* Hide Password */
	    memset(optarg, 'X', strlen(optarg));
	    break;
	case 'l':
	    margs.lurl = xstrdup(optarg);
	    break;
	case 'b':
	    margs.lbind = xstrdup(optarg);
	    break;
	case 'm':
	    margs.mdepth = atoi(optarg);
	    break;
	case 'h':
	    fprintf(stderr, "Usage: \n");
	    fprintf(stderr, "squid_kerb_ldap [-d] [-i] -g group list [-D domain] [-N netbios domain map] [-s] [-u ldap user] [-p ldap user password] [-l ldap url] [-b ldap bind path] [-a] [-m max depth] [-h]\n");
	    fprintf(stderr, "-d full debug\n");
	    fprintf(stderr, "-i informational messages\n");
	    fprintf(stderr, "-g group list\n");
	    fprintf(stderr, "-t group list (only group name hex UTF-8 format)\n");
	    fprintf(stderr, "-T group list (all in hex UTF-8 format - except seperator @)\n");
	    fprintf(stderr, "-D default domain\n");
	    fprintf(stderr, "-N netbios to dns domain map\n");
	    fprintf(stderr, "-u ldap user\n");
	    fprintf(stderr, "-p ldap user password\n");
	    fprintf(stderr, "-l ldap url\n");
	    fprintf(stderr, "-b ldap bind path\n");
	    fprintf(stderr, "-s use SSL encryption with Kerberos authentication\n");
	    fprintf(stderr, "-a allow SSL without cert verification\n");
	    fprintf(stderr, "-m maximal depth for recursive searches\n");
	    fprintf(stderr, "-h help\n");
	    fprintf(stderr, "The ldap url, ldap user and ldap user password details are only used if the kerberised\n");
	    fprintf(stderr, "access fails(e.g. unknown domain) or if the username does not contain a domain part\n");
	    fprintf(stderr, "and no default domain is provided.\n");
	    fprintf(stderr, "If the ldap url starts with ldaps:// it is either start_tls or simple SSL\n");
	    fprintf(stderr, "The group list can be:\n");
	    fprintf(stderr, "group   - In this case group can be used for all keberised and non kerberised ldap servers\n");
	    fprintf(stderr, "group@  - In this case group can be used for all keberised ldap servers\n");
	    fprintf(stderr, "group@domain  - In this case group can be used for ldap servers of domain domain\n");
	    fprintf(stderr, "group1@domain1:group2@domain2:group3@:group4  - A list is build with a colon as seperator\n");
	    fprintf(stderr, "Group membership is determined with AD servers through the users memberof attribute which\n");
	    fprintf(stderr, "is followed to the top (e.g. if the group is a member of a group)\n");
	    fprintf(stderr, "Group membership is determined with non AD servers through the users memberuid (assuming\n");
	    fprintf(stderr, "PosixGroup) or primary group membership (assuming PosixAccount)\n");
	    clean_args(&margs);
	    exit(0);
	default:
	    warn((char *) "%s| %s: WARNING: unknown option: -%c.\n", LogTime(), PROGRAM, opt);
	}
    }

    debug((char *) "%s| %s: INFO: Starting version %s\n", LogTime(), PROGRAM, KERBEROS_LDAP_GROUP_VERSION);
    if (create_gd(&margs)) {
	debug((char *) "%s| %s: FATAL: Error in group list: %s\n", LogTime(), PROGRAM, margs.glist ? margs.glist : "NULL");
	SEND_ERR("");
	clean_args(&margs);
	exit(1);
    }
    if (create_nd(&margs)) {
	debug((char *) "%s| %s: FATAL: Error in netbios list: %s\n", LogTime(), PROGRAM, margs.nlist ? margs.nlist : "NULL");
	SEND_ERR("");
	clean_args(&margs);
	exit(1);
    }
    while (1) {
	if (fgets(buf, sizeof(buf) - 1, stdin) == NULL) {
	    if (ferror(stdin)) {
		debug((char *) "%s| %s: FATAL: fgets() failed! dying..... errno=%d (%s)\n", LogTime(), PROGRAM, ferror(stdin),
		    strerror(ferror(stdin)));

		SEND_ERR("");
		clean_args(&margs);
		exit(1);	/* BIIG buffer */
	    }
	    SEND_ERR("");
	    clean_args(&margs);
	    exit(0);
	}
	c = (char *) memchr(buf, '\n', sizeof(buf) - 1);
	if (c) {
	    *c = '\0';
	    length = c - buf;
	} else {
	    SEND_ERR("");
	    debug((char *) "%s| %s: ERR\n", LogTime(), PROGRAM);
	    continue;
	}

	user = buf;
	nuser = strchr(user, '\\');
	if (!nuser)
	    nuser8 = strstr(user, "%5C");
	if (!nuser && !nuser8)
	    nuser8 = strstr(user, "%5c");
	domain = strrchr(user, '@');
	if (nuser || nuser8) {
	    if (nuser) {
		*nuser = '\0';
		nuser++;
	    } else {
		*nuser8 = '\0';
		nuser = nuser8 + 3;
	    }
	    netbios = user;
	    if (debug_enabled)
		debug((char *) "%s| %s: INFO: Got User: %s Netbios Name: %s\n", LogTime(), PROGRAM, nuser, netbios);
	    else
		log((char *) "%s| %s: INFO: Got User: %s Netbios Name: %s\n", LogTime(), PROGRAM, nuser, netbios);
	    domain = get_netbios_name(&margs, netbios);
	    user = nuser;
	} else if (domain) {
	    strup(domain);
	    *domain = '\0';
	    domain++;
	}
	if (!domain && margs.ddomain) {
	    domain = xstrdup(margs.ddomain);
	    if (debug_enabled)
		debug((char *) "%s| %s: INFO: Got User: %s set default domain: %s\n", LogTime(), PROGRAM, user, domain);
	    else
		log((char *) "%s| %s: INFO: Got User: %s set default domain: %s\n", LogTime(), PROGRAM, user, domain);
	}
	if (debug_enabled)
	    debug((char *) "%s| %s: INFO: Got User: %s Domain: %s\n", LogTime(), PROGRAM, user, domain ? domain : "NULL");
	else
	    log((char *) "%s| %s: INFO: Got User: %s Domain: %s\n", LogTime(), PROGRAM, user, domain ? domain : "NULL");

	if (!strcmp(user, "QQ") && domain && !strcmp(domain, "QQ")) {
	    clean_args(&margs);
	    exit(-1);
	}
	if (check_memberof(&margs, user, domain)) {
	    SEND_OK("");
	    debug((char *) "%s| %s: DEBUG: OK\n", LogTime(), PROGRAM);
	} else {
	    SEND_ERR("");
	    debug((char *) "%s| %s: DEBUG: ERR\n", LogTime(), PROGRAM);
	}
    }


