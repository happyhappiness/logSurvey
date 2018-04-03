    return httpHeaderParse(&req->header, blk_start, blk_end);
}

/* swaps out request-line and headers, appends <crlf> terminator */
void
httpRequestSwapOut(const request_t *req, StoreEntry *e)
{
    assert(req && e);
    /* store request-line */
    storeAppendPrintf(e, "%s %s HTTP/1.0\r\n",
	RequestMethodStr[req->method], req->urlpath);
    /* store headers */
    {
	Packer p;
	packerToStoreInit(&p, e);
	httpHeaderPackInto(&req->header, &p);
	packerClean(&p);
    }
    /* trailer */
    storeAppend(e, "\r\n", 2);
}

#if UNUSED_CODE
void
httpRequestSetHeaders(request_t *req, method_t method, const char *uri, const char *header_str)
{
#if OLD_CODE
    MemBuf mb;
    assert(req && uri && header_str);
    assert(!req->prefix);
