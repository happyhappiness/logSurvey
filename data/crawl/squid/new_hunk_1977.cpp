#include "acl/Checklist.h"
#endif

void httpHeaderPutStr(HttpHeader * hdr, http_hdr_type type, const char *str)
{
    fatal ("dummy function\n");
}

HttpHeaderEntry *httpHeaderGetEntry(const HttpHeader * hdr, HttpHeaderPos * pos)
{
    fatal ("dummy function\n");
    return NULL;
}

String httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id)
{
    fatal ("dummy function\n");
    return String();
}

int httpHeaderHas(const HttpHeader * hdr, http_hdr_type type)
{
    fatal ("dummy function\n");
    return 0;
}

void httpHeaderPutContRange(HttpHeader * hdr, const HttpHdrContRange * cr)
{
    fatal ("dummy function\n");
}
