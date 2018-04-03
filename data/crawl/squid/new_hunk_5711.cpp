	    last_ditch_enabled = 1;
	    break;
#endif
	case 'd':
		debug_enabled=1;
		break;
	default:
	    fprintf(stderr, "unknown option: -%c. Exiting\n", opt);
	    usage();
