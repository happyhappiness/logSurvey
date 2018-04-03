	    last_ditch_enabled = 1;
	    break;
#endif
	default:
	    fprintf(stderr, "unknown option: -%c. Exiting\n", opt);
	    usage();
