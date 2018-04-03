                      sizeof(hostname), NULL, 0, 0);
    if (rc != 0) {
        fprintf(stderr,
                "%s| %s: error while resolving ip address with getnameinfo: %s\n",
                LogTime(), PROGRAM, xgai_strerror(rc));
        xfreeaddrinfo(hres);
        return NULL;
