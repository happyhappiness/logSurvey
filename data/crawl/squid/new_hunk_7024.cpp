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
	    case '?':		/* usage */
	    default:
		usage(argv[0]);
		break;
	    }
    }
    /* Build the HTTP request */
    snprintf(msg, BUFSIZ, "%s %s HTTP/1.0\r\n", method, url);
    if (reload) {
