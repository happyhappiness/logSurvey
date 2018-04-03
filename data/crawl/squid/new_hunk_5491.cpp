	    debug = 1;
	    break;
	case 'g':
	    use_extension_dn = 1;
	    break;
	case 'S':
	    strip_nt_domain = 1;
	    break;
	default:
	    fprintf(stderr, PROGRAM_NAME " ERROR: Unknown command line option '%c'\n", option);
	    exit(1);
	}
    }
