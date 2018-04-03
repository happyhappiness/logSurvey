    EBIT_SET(e->flags, ENTRY_SPECIAL);
    storeSetPublicKey(e);
    storeBuffer(e);
    HttpRequest *r = HttpRequest::CreateFromUrl(url);

    if (NULL == r)
        fatal("mimeLoadIcon: cannot parse internal URL");
