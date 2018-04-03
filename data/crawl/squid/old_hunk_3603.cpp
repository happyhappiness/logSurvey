    if (strcasecmp(host_name, req->hostname))
        return;

    debug(1) fprintf(stderr, "cmgr: verified auth. info.\n");

    /* ok, accept */
    xfree(req->user_name);