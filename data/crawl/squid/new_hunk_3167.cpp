        debug("Warning: using only PDCs for group validation !!!\n");

    /* Main Loop */
    while (fgets(buf, HELPER_INPUT_BUFFER, stdin)) {
        if (NULL == strchr(buf, '\n')) {
            /* too large message received.. skip and deny */
            debug("%s: ERROR: Too large: %s\n", argv[0], buf);
            while (fgets(buf, HELPER_INPUT_BUFFER, stdin)) {
                debug("%s: ERROR: Too large..: %s\n", argv[0], buf);
                if (strchr(buf, '\n') != NULL)
                    break;
            }
            SEND_ERR("Input Too Long.");
            continue;
        }
        if ((p = strchr(buf, '\n')) != NULL)
            *p = '\0';		/* strip \n */
