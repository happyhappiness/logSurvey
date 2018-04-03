    return httpHeaderParse(&req->header, blk_start, blk_end);
}

void
httpRequestSetHeaders(request_t * req, method_t method, const char *uri, const char *header_str)
{
    MemBuf mb;
    assert(req && uri && header_str);
    assert(!req->prefix);
