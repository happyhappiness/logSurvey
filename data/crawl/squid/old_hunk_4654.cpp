    fatal("Not implemented");
}

extern "C" void
    storeBuffer(StoreEntry * e)
{
    fatal("Not implemented");
}

extern "C" void
    storeBufferFlush(StoreEntry * e)
{
    fatal("Not implemented");
}

extern "C" void
    storeAppend(StoreEntry * e, const char *buf, int len)
{
    fatal("Not implemented");
}

#ifndef _USE_INLINE_
#include "Store.cci"
#endif
