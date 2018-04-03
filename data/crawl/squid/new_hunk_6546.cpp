    /* host | time | user | passwd */
    snprintf(buf, sizeof(buf), "%s|%d|%s|%s",
	req->hostname,
	(int) now,
	req->user_name ? req->user_name : "",
	req->passwd);
    debug(3) fprintf(stderr, "cmgr: pre-encoded for pub: %s\n", buf);
