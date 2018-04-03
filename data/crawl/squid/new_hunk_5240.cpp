    /* Connect stdio to /dev/null in daemon mode */
    nullfd = open("/dev/null", O_RDWR | O_TEXT);

    if (nullfd < 0)
        fatalf("/dev/null: %s\n", xstrerror());

    dup2(nullfd, 0);

    if (opt_debug_stderr < 0) {