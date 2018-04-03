            /* fall thru to default */
        default:
            fprintf(stderr, "FATAL: Unknown option: -%c\n", opt);
            usage(argv[0]);
            exit(1);
        }
    }
