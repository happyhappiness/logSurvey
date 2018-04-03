    assert(mem->inmem_hi == 0);
    storeBuffer(entry);
    rep = errorBuildReply(err);
    httpReplySwapOut(rep, entry);
    httpReplyDestroy(rep);
    mem->reply->sline.status = err->http_status;
