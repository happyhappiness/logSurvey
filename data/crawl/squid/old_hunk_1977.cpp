#include "acl/Checklist.h"
#endif

SQUIDCEXTERN void httpHeaderPutStr(HttpHeader * hdr, http_hdr_type type, const char *str)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN HttpHeaderEntry *httpHeaderGetEntry(const HttpHeader * hdr, HttpHeaderPos * pos)
{
    fatal ("dummy function\n");
    return NULL;
}

extern String httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id)
{
    fatal ("dummy function\n");
    return String();
}

SQUIDCEXTERN int httpHeaderHas(const HttpHeader * hdr, http_hdr_type type)
{
    fatal ("dummy function\n");
    return 0;
}

SQUIDCEXTERN void httpHeaderPutContRange(HttpHeader * hdr, const HttpHdrContRange * cr)
{
    fatal ("dummy function\n");
}
