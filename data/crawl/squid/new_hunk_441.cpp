/// \ingroup StoreAPI
typedef void (*STOREGETCLIENT) (StoreEntry *, void *cbdata);

namespace Store {
void Stats(StoreEntry *output);
void Maintain(void *unused);
};

/// \ingroup StoreAPI
size_t storeEntryInUse();

