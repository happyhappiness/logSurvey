	    fatal("Need to add -DMALLOC_DBG when compiling to use -m option");
#endif
	case 's':
	    opt_syslog_enable = 1;
	    break;
	case 'u':
	    icpPortNumOverride = atoi(optarg);
