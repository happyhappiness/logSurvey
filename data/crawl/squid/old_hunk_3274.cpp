            no_acct_mgmt = 1;
            break;
        default:
            fprintf(stderr, "Unknown getopt value '%c'\n", ch);
            usage(argv[0]);
            exit(1);
        }
    }
start:
    if (optind < argc) {
        fprintf(stderr, "Unknown option '%s'\n", argv[optind]);
        usage(argv[0]);
        exit(1);
    }

    while (fgets(buf, BUFSIZE, stdin)) {
        user = buf;
        password_buf = strchr(buf, '\n');
        if (!password_buf) {
            fprintf(stderr, "authenticator: Unexpected input '%s'\n", buf);
            goto error;
        }
        *password_buf = '\0';
        password_buf = strchr(buf, ' ');
        if (!password_buf) {
            fprintf(stderr, "authenticator: Unexpected input '%s'\n", buf);
            goto error;
        }
        *password_buf++ = '\0';
