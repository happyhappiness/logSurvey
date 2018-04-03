    EBIT_SET(e->flags, ENTRY_SPECIAL);
    storeSetPublicKey(e);
    storeBuffer(e);
    e->mem_obj->request = requestLink(urlParse(METHOD_GET, url));
    httpReplyReset(reply = e->mem_obj->reply);
    httpBuildVersion(&version, 1, 0);
    httpReplySetHeaders(reply, version, HTTP_OK, NULL,