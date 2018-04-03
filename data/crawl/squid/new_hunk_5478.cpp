
#include "ufscommon.h"
#include "Store.h"
#include "RefCount.h"

CBDATA_CLASS_INIT(RebuildState);

void *
RebuildState::operator new (size_t size)
{
    assert (size == sizeof(RebuildState));
    CBDATA_INIT_TYPE(RebuildState);
    RebuildState *result = cbdataAlloc(RebuildState);
    /* Mark result as being owned - we want the refcounter to do the delete
     * call */
    cbdataReference(result);
    return result;
}
 
void
RebuildState::operator delete (void *address)
{
    RebuildState *t = static_cast<RebuildState *>(address);
    cbdataFree(address);
    /* And allow the memory to be freed */
    cbdataReferenceDone (t);
}

void
RebuildState::deleteSelf() const
{
    delete this;
}

RebuildState::~RebuildState()
{
    store_dirs_rebuilding--;
    sd->closeTmpSwapLog();
    storeRebuildComplete(&counts);
}

void
RebuildState::RebuildFromDirectory(void *data)
{
    RebuildState *rb = (RebuildState *)data;
    rb->rebuildFromDirectory();
}

void
RebuildState::rebuildFromDirectory()
{
    LOCAL_ARRAY(char, hdr_buf, SM_PAGE_SIZE);
    StoreEntry *e = NULL;
    StoreEntry tmpe;
    cache_key key[MD5_DIGEST_CHARS];
    struct stat sb;
    int swap_hdr_len;
    int fd = -1;
    tlv *tlv_list;
    tlv *t;
    assert(this != NULL);
    debug(47, 3) ("commonUfsDirRebuildFromDirectory: DIR #%d\n", sd->index);
    for (int count = 0; count < speed; count++) {
	assert(fd == -1);
	sfileno filn = 0;
	int size;
	fd = getNextFile(&filn, &size);
	if (fd == -2) {
	    debug(47, 1) ("Done scanning %s swaplog (%d entries)\n",
		sd->path, n_read);
	    deleteSelf();
	    return;
	} else if (fd < 0) {
	    continue;
