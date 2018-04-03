                 req->action,
                 make_auth_header(req));
    if (write(s, buf, l) < 0) {
        fprintf(stderr,"ERROR: (%d) writing request: '%s'\n", errno, buf);
    } else {
        debug("wrote request: '%s'\n", buf);
    }
    return read_reply(s, req);
}
