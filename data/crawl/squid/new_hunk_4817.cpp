    return 0;
}

SQUIDCEXTERN void httpHeaderPutContRange(HttpHeader * hdr, const HttpHdrContRange * cr)
{
    fatal ("dummy function\n");
}

void
testRangeParser(char const *rangestring)
{
