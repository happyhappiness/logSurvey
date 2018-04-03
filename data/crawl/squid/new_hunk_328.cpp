    /* Connect stdio to /dev/null in daemon mode */
    nullfd = open(_PATH_DEVNULL, O_RDWR | O_TEXT);

    if (nullfd < 0) {
        int xerrno = errno;
        fatalf(_PATH_DEVNULL " %s\n", xstrerr(xerrno));
    }

    dup2(nullfd, 0);
