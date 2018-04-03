	    printf("dnsserver version %s\n", SQUID_VERSION);
	    exit(0);
	    break;
	case 'h':
	default:
	    usage();
	    exit(1);
	    break;
	}
    }

    for (;;) {
	memset(request, '\0', REQ_SZ);
	if (fgets(request, REQ_SZ, stdin) == NULL)
	    exit(1);
	t = strrchr(request, '\n');
	if (t == NULL)		/* Ignore if no newline */
	    continue;
	*t = '\0';		/* strip NL */
	if ((t = strrchr(request, '\r')) != NULL)
	    *t = '\0';		/* strip CR */
	lookup(request);
	fflush(stdout);
    }
    /* NOTREACHED */
    return 0;
