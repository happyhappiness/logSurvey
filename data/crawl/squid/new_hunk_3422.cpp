                      sizeof(hostname), NULL, 0, 0);
    if (rc != 0) {
        fprintf(stderr,
                "%s| %s: ERROR: resolving ip address with getnameinfo: %s failed\n",
                LogTime(), PROGRAM, xgai_strerror(rc));
        xfreeaddrinfo(hres);
        return NULL;
