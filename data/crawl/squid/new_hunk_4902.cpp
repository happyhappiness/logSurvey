#include "squid.h"
#include "Store.h"
#include "comm.h"
#include "pconn.h"
#include "fde.h"

#define PCONN_FDS_SZ	8	/* pconn set size, increase for better memcache hit rate */

static PconnModule *ThePconnModule = NULL;
static MemAllocator *pconn_fds_pool = NULL;
static OBJH PconnModuleDumpWrapper;
CBDATA_CLASS_INIT(IdleConnList);

/* ========== IdleConnList ============================================ */

IdleConnList::IdleConnList(const char *key, PconnPool *thePool) : parent(thePool)
{
    hash.key = xstrdup(key);
    nfds_alloc = PCONN_FDS_SZ;
    nfds = 0;
    fds = (int *)pconn_fds_pool->alloc();
}

IdleConnList::~IdleConnList()
{

    parent->unlinkList(this);

    if (nfds_alloc == PCONN_FDS_SZ)
        pconn_fds_pool->free(fds);
    else
        xfree(fds);

    xfree(hash.key);
}

int
IdleConnList::findFDIndex (int fd)
{
    int index;

    for (index = nfds - 1; index >= 0; --index) {
        if (fds[index] == fd)
            return index;
    }

    return -1;
}

void
IdleConnList::removeFD(int fd)
{
    int index = findFDIndex(fd);
    assert(index >= 0);
    debug(48, 3) ("IdleConnList::removeFD: found FD %d at index %d\n", fd, index);

    for (; index < nfds - 1; index++)
        fds[index] = fds[index + 1];

    if (--nfds == 0) {
        debug(48, 3) ("IdleConnList::removeFD: deleting %s\n", hashKeyStr(&hash));
        delete this;
    }
}

void
IdleConnList::clearHandlers(int fd)
{
    comm_read_cancel(fd, IdleConnList::read, this);
    commSetTimeout(fd, -1, NULL, NULL);
}

void
IdleConnList::push(int fd)
{
    if (nfds == nfds_alloc) {
        debug(48, 3) ("IdleConnList::push: growing FD array\n");
        nfds_alloc <<= 1;
        int *old = fds;
        fds = (int *)xmalloc(nfds_alloc * sizeof(int));
        xmemcpy(fds, old, nfds * sizeof(int));

        if (nfds == PCONN_FDS_SZ)
            pconn_fds_pool->free(old);
        else
            xfree(old);
    }

    fds[nfds++] = fd;
    comm_read(fd, fakeReadBuf, sizeof(fakeReadBuf), IdleConnList::read, this);
    commSetTimeout(fd, Config.Timeout.pconn, IdleConnList::timeout, this);
}

/*
 * XXX this routine isn't terribly efficient - if there's a pending
 * read event (which signifies the fd will close in the next IO loop!)
 * we ignore the FD and move onto the next one. This means, as an example,
 * if we have a lot of FDs open to a very popular server and we get a bunch
 * of requests JUST as they timeout (say, it shuts down) we'll be wasting
 * quite a bit of CPU. Just keep it in mind.
 */
int
IdleConnList::findUseableFD()
{
    assert(nfds);

    for (int i = 0; i< nfds; i++) {
        if (!comm_has_pending_read_callback(fds[i])) {
            return fds[i];
        }
    }

    return -1;
}

void
IdleConnList::read(int fd, char *buf, size_t len, comm_err_t flag, int xerrno, void *data)
{
    debug(48, 3) ("IdleConnList::read: %d bytes from FD %d\n", (int) len, fd);

    if (flag == COMM_ERR_CLOSING) {
        /* Bail out early on COMM_ERR_CLOSING - close handlers will tidy up for us */
        return;
    }

    IdleConnList *list = (IdleConnList *) data;
    list->removeFD(fd);	/* might delete list */
    comm_close(fd);
}

void
IdleConnList::timeout(int fd, void *data)
{
    debug(48, 3) ("IdleConnList::timeout: FD %d\n", fd);
    IdleConnList *list = (IdleConnList *) data;
    list->removeFD(fd);	/* might delete list */
    comm_close(fd);
}

/* ========== PconnPool PRIVATE FUNCTIONS ============================================ */

const char *
PconnPool::key(const char *host, u_short port, const char *domain)
{
    LOCAL_ARRAY(char, buf, SQUIDHOSTNAMELEN * 2 + 10);

    if (domain)
        snprintf(buf, SQUIDHOSTNAMELEN * 2 + 10, "%s:%d/%s", host, (int) port, domain);
    else
        snprintf(buf, SQUIDHOSTNAMELEN * 2 + 10, "%s:%d", host, (int) port);

    return buf;
}

void
PconnPool::dumpHist(StoreEntry * e)
{
    int i;
    storeAppendPrintf(e,
                      "%s persistent connection counts:\n"
                      "\n"
                      "\treq/\n"
                      "\tconn      count\n"
                      "\t----  ---------\n",
                      descr);

    for (i = 0; i < PCONN_HIST_SZ; i++) {
        if (hist[i] == 0)
            continue;

        storeAppendPrintf(e, "\t%4d  %9d\n", i, hist[i]);
    }
}

/* ========== PconnPool PUBLIC FUNCTIONS ============================================ */

PconnPool::PconnPool(const char *aDescr) : table(NULL), descr(aDescr)
{
    int i;
    table = hash_create((HASHCMP *) strcmp, 229, hash_string);

    for (i = 0; i < PCONN_HIST_SZ; i++)
        hist[i] = 0;

    if (ThePconnModule == NULL)
        ThePconnModule = new PconnModule;

    ThePconnModule->add
    (this);
}

void
PconnPool::push(int fd, const char *host, u_short port, const char *domain)
{

    IdleConnList *list;
    const char *aKey;
    LOCAL_ARRAY(char, desc, FD_DESC_SZ);

    if (fdUsageHigh()) {
        debug(48, 3) ("PconnPool::push: Not many unused FDs\n");
        comm_close(fd);
        return;
    } else if (shutting_down) {
        comm_close(fd);
        return;
    }

    aKey = key(host, port, domain);

    list = (IdleConnList *) hash_lookup(table, aKey);

    if (list == NULL) {
        list = new IdleConnList(aKey, this);
        debug(48, 3) ("pconnNew: adding %s\n", hashKeyStr(&list->hash));
        hash_join(table, &list->hash);
    }

    list->push(fd);

    assert(!comm_has_incomplete_write(fd));
    snprintf(desc, FD_DESC_SZ, "%s idle connection", host);
    fd_note(fd, desc);
    debug(48, 3) ("PconnPool::push: pushed FD %d for %s\n", fd, aKey);
}

/*
 * return a pconn fd for host:port, or -1 if none are available
 */
int
PconnPool::pop(const char *host, u_short port, const char *domain)
{
    IdleConnList *list;
    const char * aKey = key(host, port, domain);
    list = (IdleConnList *)hash_lookup(table, aKey);

    if (list == NULL)
        return -1;

    int fd = list->findUseableFD();

    if (fd >= 0) {
        list->clearHandlers(fd);
        list->removeFD(fd);	/* might delete list */
    }

    return fd;
}

void
PconnPool::unlinkList(IdleConnList *list) const
{
    hash_remove_link(table, &list->hash);
}

void
PconnPool::count(int uses)
{
    if (uses >= PCONN_HIST_SZ)
        uses = PCONN_HIST_SZ - 1;

    hist[uses]++;
}

/* ========== PconnModule ============================================ */

/*
 * This simple class exists only for the cache manager
 */

PconnModule::PconnModule() : pools(NULL), poolCount(0)
{
    pools = (PconnPool **) xcalloc(MAX_NUM_PCONN_POOLS, sizeof(*pools));
    cachemgrRegister("pconn",
                     "Persistent Connection Utilization Histograms",
                     PconnModuleDumpWrapper, 0, 1);
    pconn_fds_pool = MemPools::GetInstance().create("pconn_fds", PCONN_FDS_SZ * sizeof(int));
    debug(48, 0) ("persistent connection module initialized\n");
}

void

PconnModule::add
    (PconnPool *aPool)
{
    assert(poolCount < MAX_NUM_PCONN_POOLS);
    *(pools+poolCount) = aPool;
    poolCount++;
}

void
PconnModule::dump(StoreEntry *e)
{
    int i;

    for (i = 0; i < poolCount; i++) {
        (*(pools+i))->dumpHist(e);
    }
}

static void
PconnModuleDumpWrapper(StoreEntry *e)
{
    ThePconnModule->dump(e);
}
