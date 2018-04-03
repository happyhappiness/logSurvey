            check_pw = 1;
            break;
        case 'g':
	    grents = realloc(grents, sizeof(*grents) * (ngroups+1));
            grents[ngroups++] = optarg;
            break;
        case '?':
            if (xisprint(optopt)) {
                fprintf(stderr, "Unknown option '-%c'.\n", optopt);
            } else {
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
