#endif
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
