		method = xstrdup("TRACE");
		max_forwards = atoi(optarg);
		break;
	    case '?':		/* usage */
	    default:
		usage(argv[0]);
		break;
	    }
    }
    /* Connect to the server */
    if ((conn = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
	perror("client: socket");
	exit(1);
    }
    if (client_comm_connect(conn, hostname, port) < 0) {
	if (errno == 0) {
	    fprintf(stderr, "client: ERROR: Cannot connect to %s:%d: Host unknown.\n", hostname, port);
	} else {
	    char tbuf[BUFSIZ];
	    snprintf(tbuf, BUFSIZ, "client: ERROR: Cannot connect to %s:%d",
		hostname, port);
	    perror(tbuf);
	}
	exit(1);
    }
    /* Build the HTTP request */
    snprintf(msg, BUFSIZ, "%s %s HTTP/1.0\r\n", method, url);
    if (reload) {
