            opt = optopt;
            /* fall thru to default */
        default:
            fprintf(stderr, "%s Unknown option: -%c. Exiting\n", myname, opt);
            usage(argv[0]);
            exit(1);
            break;		/* not reached */
