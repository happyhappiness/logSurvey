	    _res.options |= RES_DNSRCH;
#endif
	    break;
	case 'd':
	    snprintf(buf, 256, "dnsserver.%d.log", (int) getpid());
	    logfile = fopen(buf, "a");
	    do_debug++;
	    if (!logfile)
		fprintf(stderr, "Could not open dnsserver's log file\n");
	    break;
	case 'h':
	    fprintf(stderr, "usage: dnsserver -hvd\n");
	    exit(1);
	    break;
	case 's':
	    if (opt_s == 0) {
		_res.nscount = 0;
		_res.options |= RES_INIT;
		opt_s = 1;
	    }
	    safe_inet_addr(optarg, &_res.nsaddr_list[_res.nscount++].sin_addr);
	    break;
	case 'v':
	    printf("dnsserver version %s\n", SQUID_VERSION);
	    exit(0);
	    break;
	default:
	    fprintf(stderr, "usage: dnsserver -hvd\n");
	    exit(1);
