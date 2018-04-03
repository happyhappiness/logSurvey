    return os;
}

size_t storeEntryInUse() STUB_RETVAL(0)
const char *storeEntryFlags(const StoreEntry *) STUB_RETVAL(NULL)
void storeEntryReplaceObject(StoreEntry *, HttpReply *) STUB
StoreEntry *storeGetPublic(const char *uri, const HttpRequestMethod& method) STUB_RETVAL(NULL)
StoreEntry *storeGetPublicByRequest(HttpRequest * request) STUB_RETVAL(NULL)
StoreEntry *storeGetPublicByRequestMethod(HttpRequest * request, const HttpRequestMethod& method) STUB_RETVAL(NULL)
extern StoreEntry *storeCreateEntry(const char *, const char *, const RequestFlags &, const HttpRequestMethod&) STUB_RETVAL(NULL)
void storeInit(void) STUB
void storeConfigure(void) STUB
void storeFreeMemory(void) STUB
int expiresMoreThan(time_t, time_t) STUB_RETVAL(0)
void storeAppendPrintf(StoreEntry *, const char *,...) STUB
void storeAppendVPrintf(StoreEntry *, const char *, va_list ap) STUB
int storeTooManyDiskFilesOpen(void) STUB_RETVAL(0)
void storeHeapPositionUpdate(StoreEntry *, SwapDir *) STUB
void storeSwapFileNumberSet(StoreEntry * e, sfileno filn) STUB
void storeFsInit(void) STUB
void storeFsDone(void) STUB
void storeReplAdd(const char *, REMOVALPOLICYCREATE *) STUB
void destroyStoreEntry(void *) STUB
// in Packer.cc !? void packerToStoreInit(Packer * p, StoreEntry * e) STUB
void storeGetMemSpace(int size) STUB

#if !_USE_INLINE_
#include "Store.cci"
