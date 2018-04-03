    if (strcasecmp(host_name, req->hostname))
        return;

    debug("cmgr: verified auth. info.\n");

    /* ok, accept */
    xfree(req->user_name);