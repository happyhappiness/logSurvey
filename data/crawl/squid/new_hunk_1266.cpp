    assert(http != NULL);
    assert(http->storeEntry() == NULL);

    HttpReply *const reply = Ftp::HttpReplyWrapper(code, msg, Http::scNoContent, 0);

    setLogUri(http, urlCanonicalClean(http->request));

