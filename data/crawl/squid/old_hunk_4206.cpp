    ping_int = 1 * 1000;

    if (argc < 2) {
	usage(argv[0]);		/* need URL */
    } else if (argc >= 2) {
	strncpy(url, argv[argc - 1], BUFSIZ);
	url[BUFSIZ - 1] = '\0';

	if (url[0] == '-')
	    usage(argv[0]);

	while ((c = getopt(argc, argv, "ah:l:P:i:km:p:rsvt:g:p:I:H:T:u:U:w:W:?")) != -1)
	    switch (c) {

	    case 'a':
		opt_noaccept = 1;
		break;

	    case 'h':		/* remote host */

		if (optarg != NULL)
		    hostname = optarg;

		break;

	    case 'l':		/* local host */
		if (optarg != NULL)
		    localhost = optarg;

		break;

	    case 's':		/* silent */
		to_stdout = 0;

		break;

	    case 'k':		/* backward compat */
		keep_alive = 1;

		break;

	    case 'r':		/* reload */
		reload = 1;

		break;

	    case 'p':		/* port number */
		sscanf(optarg, "%d", &port);

		if (port < 1)
		    port = CACHE_HTTP_PORT;	/* default */

		break;

	    case 'P':
		put_file = xstrdup(optarg);

		break;

	    case 'i':		/* IMS */
		ims = (time_t) atoi(optarg);

		break;

	    case 'm':
		method = xstrdup(optarg);

		break;

	    case 't':
		method = xstrdup("TRACE");

		max_forwards = atoi(optarg);

		break;

	    case 'g':
		ping = 1;

		pcount = atoi(optarg);

		to_stdout = 0;

		break;

	    case 'I':
		if ((ping_int = atoi(optarg) * 1000) <= 0)
		    usage(argv[0]);

		break;

	    case 'H':
		if (strlen(optarg)) {
		    char *t;
		    strncpy(extra_hdrs, optarg, sizeof(extra_hdrs));

		    while ((t = strstr(extra_hdrs, "\\n")))
			*t = '\r', *(t + 1) = '\n';
		}
		break;

	    case 'T':
		io_timeout = atoi(optarg);
		break;

	    case 'u':
		proxy_user = optarg;
		break;

	    case 'w':
		proxy_password = optarg;
		break;

	    case 'U':
		www_user = optarg;
		break;

	    case 'W':
		www_password = optarg;
		break;

	    case 'v':
		/* undocumented: may increase verb-level by giving more -v's */
		opt_verbose++;
		break;

	    case '?':		/* usage */

	    default:
		usage(argv[0]);
		break;
	    }
    }
#ifdef _SQUID_MSWIN_
    {
	WSADATA wsaData;
	WSAStartup(2, &wsaData);
	atexit(Win32SockCleanup);
    }
#endif
    /* Build the HTTP request */
    if (strncmp(url, "mgr:", 4) == 0) {
	char *t = xstrdup(url + 4);
	snprintf(url, BUFSIZ, "cache_object://%s/%s", hostname, t);
	xfree(t);
    }
    if (put_file) {
	put_fd = open(put_file, O_RDONLY);
	set_our_signal();

	if (put_fd < 0) {
	    fprintf(stderr, "%s: can't open file (%s)\n", argv[0],
		xstrerror());
	    exit(-1);
	}
#ifdef _SQUID_WIN32_
	setmode(put_fd, O_BINARY);

#endif

	fstat(put_fd, &sb);
    }
    snprintf(msg, BUFSIZ, "%s %s HTTP/1.0\r\n", method, url);

    if (reload) {
	snprintf(buf, BUFSIZ, "Pragma: no-cache\r\n");
	strcat(msg, buf);
    }
    if (put_fd > 0) {
	snprintf(buf, BUFSIZ, "Content-length: %d\r\n", (int) sb.st_size);
	strcat(msg, buf);
    }
    if (opt_noaccept == 0) {
	snprintf(buf, BUFSIZ, "Accept: */*\r\n");
	strcat(msg, buf);
    }
    if (ims) {
	snprintf(buf, BUFSIZ, "If-Modified-Since: %s\r\n", mkrfc1123(ims));
	strcat(msg, buf);
    }
    if (max_forwards > -1) {
	snprintf(buf, BUFSIZ, "Max-Forwards: %d\r\n", max_forwards);
	strcat(msg, buf);
    }
    if (proxy_user) {
	char *user = proxy_user;
	char *password = proxy_password;
#if HAVE_GETPASS

	if (!password)
	    password = getpass("Proxy password: ");

#endif

	if (!password) {
	    fprintf(stderr, "ERROR: Proxy password missing\n");
	    exit(1);
	}
	snprintf(buf, BUFSIZ, "%s:%s", user, password);
	snprintf(buf, BUFSIZ, "Proxy-Authorization: Basic %s\r\n", base64_encode(buf));
	strcat(msg, buf);
    }
    if (www_user) {
	char *user = www_user;
	char *password = www_password;
#if HAVE_GETPASS

	if (!password)
	    password = getpass("WWW password: ");

#endif

	if (!password) {
	    fprintf(stderr, "ERROR: WWW password missing\n");
	    exit(1);
	}
	snprintf(buf, BUFSIZ, "%s:%s", user, password);
	snprintf(buf, BUFSIZ, "Authorization: Basic %s\r\n", base64_encode(buf));
	strcat(msg, buf);
    }
    if (keep_alive) {
	if (port != 80)
	    snprintf(buf, BUFSIZ, "Proxy-Connection: keep-alive\r\n");
	else
	    snprintf(buf, BUFSIZ, "Connection: keep-alive\r\n");

	strcat(msg, buf);
    }
    strcat(msg, extra_hdrs);
    snprintf(buf, BUFSIZ, "\r\n");
    strcat(msg, buf);

    if (opt_verbose)
	fprintf(stderr, "headers: '%s'\n", msg);

    if (ping) {
#if HAVE_SIGACTION

	struct sigaction sa, osa;

	if (sigaction(SIGINT, NULL, &osa) == 0 && osa.sa_handler == SIG_DFL) {
	    sa.sa_handler = catchSignal;
	    sa.sa_flags = 0;
	    sigemptyset(&sa.sa_mask);
	    (void) sigaction(SIGINT, &sa, NULL);
	}
#else
	void (*osig) (int);

	if ((osig = signal(SIGINT, catchSignal)) != SIG_DFL)
	    (void) signal(SIGINT, osig);

#endif

    }
    loops = ping ? pcount : 1;

    for (i = 0; loops == 0 || i < loops; i++) {
	int fsize = 0;
        struct addrinfo *AI = NULL;

	/* Connect to the server */

        if(localhost) {
            if( !iaddr.GetHostByName(localhost) ) {
                fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", localhost);
                exit(1);
            }
        }
        else {
            /* Process the remote host name to locate the Protocol required
               in case we are being asked to link to another version of squid */
            if( !iaddr.GetHostByName(hostname) ) {
                fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", hostname);
                exit(1);
            }
