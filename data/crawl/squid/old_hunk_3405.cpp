                LogTime(), PROGRAM, hostname);
        return NULL;
    }
    rc = xgetaddrinfo(hostname, NULL, NULL, &hres);
    if (rc != 0) {
        fprintf(stderr,
                "%s| %s: ERROR: resolving hostname with getaddrinfo: %s failed\n",
                LogTime(), PROGRAM, xgai_strerror(rc));
        return NULL;
    }
    hres_list = hres;
