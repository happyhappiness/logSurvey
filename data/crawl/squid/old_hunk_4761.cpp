     * 1.1.3.  execvp had a bit overflow error in a loop..
     */
    /* Connect stdio to /dev/null in daemon mode */
    nullfd = open("/dev/null", O_RDWR | O_TEXT);

    if (nullfd < 0)
        fatalf("/dev/null: %s\n", xstrerror());

    dup2(nullfd, 0);
