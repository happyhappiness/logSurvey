		usage();
	    break;
	case 'm':
#if MALLOC_DBG
	    malloc_debug_level = atoi(optarg);
	    /* NOTREACHED */
	    break;
#else
	    fatal("Need to add -DMALLOC_DBG when compiling to use -m option");
	    /* NOTREACHED */
#endif
	case 's':
	    opt_syslog_enable = 1;
	    break;
