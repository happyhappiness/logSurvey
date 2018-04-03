#include "ACLChecklist.h"

/* Stub routines */
SQUIDCEXTERN void
cachemgrRegister(const char *, const char *, OBJH *, int, int)
{}

SQUIDCEXTERN void httpHeaderPutStr(HttpHeader * hdr, http_hdr_type type, const char *str)
{
    fatal ("dummy function\n");
}

#if STDC_HEADERS
SQUIDCEXTERN void
storeAppendPrintf(StoreEntry *, const char *,...)
#else
SQUIDCEXTERN void storeAppendPrintf()
#endif
{
    fatal ("dummy function\n");
}

extern
void eventAdd(const char *name, EVH * func, void *arg, double when, int, bool)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN void
storeBuffer(StoreEntry * e)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN void
storeBufferFlush(StoreEntry * e)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN void storeAppend(StoreEntry *, const char *, int)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN void storeAppendVPrintf(StoreEntry *, const char *, va_list ap)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN void httpHeaderDelAt(HttpHeader * hdr, HttpHeaderPos pos)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN HttpHeaderEntry *httpHeaderGetEntry(const HttpHeader * hdr, HttpHeaderPos * pos)
{
    fatal ("dummy function\n");
    return NULL;
}

int
ACLChecklist::fastCheck()
{
    fatal ("dummy function\n");
    return 0;
}

void
ACLChecklist::operator delete (void *address)
{
    safe_free( address);
}

ACLChecklist::~ACLChecklist(){}

SQUIDCEXTERN ACLChecklist *aclChecklistCreate(const acl_access *,
        HttpRequest *,
        const char *ident)
{
    fatal ("dummy function\n");
    return NULL;
}

extern String httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id)
{
    fatal ("dummy function\n");
