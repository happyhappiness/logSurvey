            opt = optopt;
            /* fall thru to default */
        default:
            fprintf(stderr, "ERROR: unknown option: -%c. Exiting\n", opt);
            usage();
            had_error = 1;
        }
