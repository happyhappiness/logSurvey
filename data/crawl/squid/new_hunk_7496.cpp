	    break;
#else
	    fatal("Need to add -DMALLOC_DBG when compiling to use -m option");
	    /* NOTREACHED */
#endif
	case 's':
	    opt_syslog_enable = 1;
