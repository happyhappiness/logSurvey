            usage();
            exit(0);
        default:
            fprintf(stderr, "%s: FATAL: unknown option: -%c. Exiting\n", program_name, opt);
            usage();
            exit(1);
        }
