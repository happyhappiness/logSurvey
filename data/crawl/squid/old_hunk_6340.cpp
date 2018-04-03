    return httpHeaderParse(&req->header, blk_start, blk_end);
}

/* swaps out request-line and headers, appends <crlf> terminator */
void
httpRequestSwapOut(const request_t * req, StoreEntry * e)
{
    assert(req && e);
    /* store request-line */
    storeAppendPrintf(e, "%s %s HTTP/1.0\r\n",
	RequestMethodStr[req->method], strBuf(req->urlpath));
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
