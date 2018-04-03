        }
    }
    if (optind < argc) {
        fprintf(stderr, "Unknown option '%s'\n", argv[optind]);
        usage(argv[0]);
        exit(1);
    }
    while (fgets(buf, sizeof(buf), stdin)) {
        j = 0;
        if ((p = strchr(buf, '\n')) == NULL) {
            /* too large message received.. skip and deny */
            fprintf(stderr, "%s: ERROR: Too large: %s\n", argv[0], buf);
            while (fgets(buf, sizeof(buf), stdin)) {
                fprintf(stderr, "%s: ERROR: Too large..: %s\n", argv[0], buf);
                if (strchr(buf, '\n') != NULL)
                    break;
            }
            goto error;
        }
        *p = '\0';
        if ((p = strtok(buf, " ")) == NULL) {
            goto error;
        } else {
            user = p;
            rfc1738_unescape(user);
