    /* add custom headers */
    assert(!req->header.len);

    req->header.putStr(Http::HdrType::ACCEPT, StoreDigestMimeStr);

    req->header.putStr(Http::HdrType::ACCEPT, "text/html");

    if (p->login &&
            p->login[0] != '*' &&
