    static char buf[1024];
    safe_free(req->pub_auth);
    debug(3) fprintf(stderr, "cmgr: encoding for pub...\n");
    if (!req->passwd || !strlen(req->passwd))
	return;
    /* host | time | user | passwd */
    snprintf(buf, sizeof(buf), "%s|%d|%s|%s",
