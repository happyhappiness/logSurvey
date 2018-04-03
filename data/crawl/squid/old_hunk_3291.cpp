    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    while (1) {
        /* Read whole line from standard input. Terminate on break. */
        if (fgets(wstr, 255, stdin) == NULL)
            break;

        if (NULL == strchr(wstr, '\n')) {
            err = 1;
            continue;
        }
        if (err) {
            fprintf(stderr, "Oversized message\n");
            puts("ERR");
            goto error;
        }

        if ((p = strchr(wstr, '\n')) != NULL)
