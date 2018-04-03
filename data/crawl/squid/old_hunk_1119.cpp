#endif
            break;
        case 't':
	    if (optarg)
                rcache_type = xstrdup(optarg);
	    else {
                fprintf(stderr, "ERROR: replay cache type not given\n");
		exit(1);
	    }
            break;
        case 's':
	    if (optarg)
                service_principal = xstrdup(optarg);
	    else {
                fprintf(stderr, "ERROR: service principal not given\n");
		exit(1);
	    }
            break;
        default:
            fprintf(stderr, "Usage: \n");
