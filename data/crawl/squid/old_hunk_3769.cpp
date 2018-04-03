                 req->hostname,
                 req->action,
                 make_auth_header(req));
    write(s, buf, l);
    debug(1) fprintf(stderr, "wrote request: '%s'\n", buf);
    return read_reply(s, req);
}

