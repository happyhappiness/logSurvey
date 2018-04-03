    return httpHeaderParse(&req->header, blk_start, blk_end);
}

/* swaps out request using httpRequestPack */
void
httpRequestSwapOut(const request_t * req, StoreEntry * e)
{
    Packer p;
    assert(req && e);
    packerToStoreInit(&p, e);
    httpRequestPack(req, &p);
    packerClean(&p);
}

/* packs request-line and headers, appends <crlf> terminator */
void
httpRequestPack(const request_t * req, Packer *p)
{
    assert(req && p);
    /* pack request-line */
    packerPrintf(p, "%s %s HTTP/1.0\r\n",
	RequestMethodStr[req->method], strBuf(req->urlpath));
    /* headers */
    httpHeaderPackInto(&req->header, p);
    /* trailer */
    packerAppend(p, "\r\n", 2);
}

#if UNUSED_CODE
