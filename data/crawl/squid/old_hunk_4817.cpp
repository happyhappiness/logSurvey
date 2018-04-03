    return 0;
}

SQUIDCEXTERN void httpHdrContRangeDestroy(HttpHdrContRange * crange)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN void httpHdrContRangeSet(HttpHdrContRange *, HttpHdrRangeSpec, ssize_t)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN void httpHeaderPutContRange(HttpHeader * hdr, const HttpHdrContRange * cr)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN HttpHdrContRange *httpHdrContRangeCreate(void)
{
    fatal ("dummy function\n");
    return NULL;
}

void
testRangeParser(char const *rangestring)
{
