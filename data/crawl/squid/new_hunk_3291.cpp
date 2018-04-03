    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    while (fgets(wstr, HELPER_INPUT_BUFFER, stdin) != NULL) {

        if (NULL == strchr(wstr, '\n')) {
            err = 1;
            continue;
        }
        if (err) {
            SEND_ERR("Oversized message");
            err = 0;
            fflush(stdout);
            continue;
        }

        if ((p = strchr(wstr, '\n')) != NULL)
