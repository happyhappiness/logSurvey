    S.FreeAddrInfo(AI);

    l = snprintf(buf, sizeof(buf),
                 "GET cache_object://%s/%s%s%s HTTP/1.0\r\n"
                 "Accept: */*\r\n"
                 "%s"			/* Authentication info or nothing */
                 "\r\n",
                 req->hostname,
                 req->action,
                 req->workers? "?workers=" : (req->processes ? "?processes=" : ""),
                 req->workers? req->workers : (req->processes ? req->processes: ""),
                 make_auth_header(req));
    if (write(s, buf, l) < 0) {
        fprintf(stderr,"ERROR: (%d) writing request: '%s'\n", errno, buf);
