	    use_tls = 1;
	    break;
#endif
	case 'd':
	    debug++;
	    break;
	default:
	    fprintf(stderr, PROGRAM_NAME ": ERROR: Unknown command line option '%c'\n", option);
	    exit(1);
