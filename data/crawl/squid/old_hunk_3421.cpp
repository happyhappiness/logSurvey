
    rc = gethostname(hostname, sysconf(_SC_HOST_NAME_MAX));
    if (rc) {
        fprintf(stderr, "%s| %s: error while resolving hostname '%s'\n",
                LogTime(), PROGRAM, hostname);
        return NULL;
    }
    rc = xgetaddrinfo(hostname, NULL, NULL, &hres);
    if (rc != 0) {
        fprintf(stderr,
                "%s| %s: error while resolving hostname with getaddrinfo: %s\n",
                LogTime(), PROGRAM, xgai_strerror(rc));
        return NULL;
    }