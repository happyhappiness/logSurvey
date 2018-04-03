	    load_balance = 1;
	    break;
	case 'f':
	    failover_enabled = 1;
	    break;
	case 'l':
	    last_ditch_enabled = 1;
	    break;
	default:
	    fprintf(stderr, "unknown option: -%c. Exiting\n", opt);
	    usage();
