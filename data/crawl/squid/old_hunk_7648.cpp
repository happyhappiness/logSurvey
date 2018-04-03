	    fatal("Need to add -DMALLOC_DBG when compiling to use -m option");
#endif
	case 's':
	    syslog_enable = 0;
	    break;
	case 'u':
	    icpPortNumOverride = atoi(optarg);
