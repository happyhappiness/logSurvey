 */

#include "squid.h"

HttpRequest *
requestCreate(method_t method, protocol_t protocol, const char *aUrlpath)
{
    fatal("Not implemented");
    return NULL;
}

HttpRequest *
requestLink(HttpRequest * request)
{
    fatal("Not implemented");
    return NULL;
}

void
requestUnlink(HttpRequest * request)
{
    if (!request)
        return;

    fatal("Not implemented");
}

/*
