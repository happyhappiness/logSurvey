             req->user_name ? req->user_name : "",
             req->passwd);

    debug("cmgr: pre-encoded for pub: %s\n", buf);
    debug("cmgr: encoded: '%s'\n", base64_encode(buf));

    req->pub_auth = xstrdup(base64_encode(buf));
}
