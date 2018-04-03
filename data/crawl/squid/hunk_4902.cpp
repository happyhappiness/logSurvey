 #include "squid.h"
 #include "Store.h"
 #include "comm.h"
-
-struct _pconn
-{
-    hash_link hash;		/* must be first */
-    int *fds;
-    int nfds_alloc;
-    int nfds;
-    char buf[4096];
-};
-
-typedef struct _pconn pconn;
+#include "pconn.h"
+#include "fde.h"
 
 #define PCONN_FDS_SZ	8	/* pconn set size, increase for better memcache hit rate */
-#define PCONN_HIST_SZ (1<<16)
-int client_pconn_hist[PCONN_HIST_SZ];
-int server_pconn_hist[PCONN_HIST_SZ];
-
-static IOCB pconnRead;
-static PF pconnTimeout;
-static const char *pconnKey(const char *host, u_short port, const char *domain);
-static hash_table *table = NULL;
-
-static struct _pconn *pconnNew(const char *key);
 
-static void pconnDelete(struct _pconn *p);
-
-static void pconnRemoveFD(struct _pconn *p, int fd);
-static OBJH pconnHistDump;
+static PconnModule *ThePconnModule = NULL;
 static MemAllocator *pconn_fds_pool = NULL;
-CBDATA_TYPE(pconn);
-
+static OBJH PconnModuleDumpWrapper;
+CBDATA_CLASS_INIT(IdleConnList);
 
+/* ========== IdleConnList ============================================ */
 
-static const char *
-pconnKey(const char *host, u_short port, const char *domain)
+IdleConnList::IdleConnList(const char *key, PconnPool *thePool) : parent(thePool)
 {
-    LOCAL_ARRAY(char, buf, SQUIDHOSTNAMELEN * 2 + 10);
-
-    if (domain)
-        snprintf(buf, SQUIDHOSTNAMELEN * 2 + 10, "%s:%d/%s", host, (int) port, domain);
-    else
-        snprintf(buf, SQUIDHOSTNAMELEN * 2 + 10, "%s:%d", host, (int) port);
-
-    return buf;
+    hash.key = xstrdup(key);
+    nfds_alloc = PCONN_FDS_SZ;
+    nfds = 0;
+    fds = (int *)pconn_fds_pool->alloc();
 }
 
-static struct _pconn *
-            pconnNew(const char *key)
+IdleConnList::~IdleConnList()
 {
-    pconn *p;
-    CBDATA_INIT_TYPE(pconn);
-    p = cbdataAlloc(pconn);
-    p->hash.key = xstrdup(key);
-    p->nfds_alloc = PCONN_FDS_SZ;
-    p->nfds = 0;
-    p->fds = (int *)pconn_fds_pool->alloc();
-    debug(48, 3) ("pconnNew: adding %s\n", hashKeyStr(&p->hash));
-    hash_join(table, &p->hash);
-    return p;
-}
 
-static void
+    parent->unlinkList(this);
 
-pconnDelete(struct _pconn *p)
-{
-    debug(48, 3) ("pconnDelete: deleting %s\n", hashKeyStr(&p->hash));
-    hash_remove_link(table, (hash_link *) p);
-
-    if (p->nfds_alloc == PCONN_FDS_SZ)
-        pconn_fds_pool->free(p->fds);
+    if (nfds_alloc == PCONN_FDS_SZ)
+        pconn_fds_pool->free(fds);
     else
-        xfree(p->fds);
-
-    xfree(p->hash.key);
+        xfree(fds);
 
-    cbdataFree(p);
+    xfree(hash.key);
 }
 
-static int
-
-pconnFindFDIndex (struct _pconn *p, int fd)
+int
+IdleConnList::findFDIndex (int fd)
 {
-    int result;
+    int index;
 
-    for (result = p->nfds - 1; result >= 0; --result)
-    {
-        if (p->fds[result] == fd)
-            return result;
+    for (index = nfds - 1; index >= 0; --index) {
+        if (fds[index] == fd)
+            return index;
     }
 
-    return p->nfds;
+    return -1;
 }
 
-static void
-
-pconnRemoveFDByIndex (struct _pconn *p, int index)
+void
+IdleConnList::removeFD(int fd)
 {
-    for (; index < p->nfds - 1; index++)
-        p->fds[index] = p->fds[index + 1];
-}
+    int index = findFDIndex(fd);
+    assert(index >= 0);
+    debug(48, 3) ("IdleConnList::removeFD: found FD %d at index %d\n", fd, index);
 
-static void
+    for (; index < nfds - 1; index++)
+        fds[index] = fds[index + 1];
 
-pconnPreventHandingOutFD(struct _pconn *p, int fd)
-{
-    int i = pconnFindFDIndex (p, fd);
-    assert(i >= 0);
-    debug(48, 3) ("pconnRemoveFD: found FD %d at index %d\n", fd, i);
-    pconnRemoveFDByIndex(p, i);
+    if (--nfds == 0) {
+        debug(48, 3) ("IdleConnList::removeFD: deleting %s\n", hashKeyStr(&hash));
+        delete this;
+    }
 }
 
-static void
+void
+IdleConnList::clearHandlers(int fd)
+{
+    comm_read_cancel(fd, IdleConnList::read, this);
+    commSetTimeout(fd, -1, NULL, NULL);
+}
 
-pconnRemoveFD(struct _pconn *p, int fd)
+void
+IdleConnList::push(int fd)
 {
-    pconnPreventHandingOutFD(p, fd);
+    if (nfds == nfds_alloc) {
+        debug(48, 3) ("IdleConnList::push: growing FD array\n");
+        nfds_alloc <<= 1;
+        int *old = fds;
+        fds = (int *)xmalloc(nfds_alloc * sizeof(int));
+        xmemcpy(fds, old, nfds * sizeof(int));
+
+        if (nfds == PCONN_FDS_SZ)
+            pconn_fds_pool->free(old);
+        else
+            xfree(old);
+    }
 
-    if (--p->nfds == 0)
-        pconnDelete(p);
+    fds[nfds++] = fd;
+    comm_read(fd, fakeReadBuf, sizeof(fakeReadBuf), IdleConnList::read, this);
+    commSetTimeout(fd, Config.Timeout.pconn, IdleConnList::timeout, this);
 }
 
-static void
-pconnTimeout(int fd, void *data)
+/*
+ * XXX this routine isn't terribly efficient - if there's a pending
+ * read event (which signifies the fd will close in the next IO loop!)
+ * we ignore the FD and move onto the next one. This means, as an example,
+ * if we have a lot of FDs open to a very popular server and we get a bunch
+ * of requests JUST as they timeout (say, it shuts down) we'll be wasting
+ * quite a bit of CPU. Just keep it in mind.
+ */
+int
+IdleConnList::findUseableFD()
 {
+    assert(nfds);
 
-    struct _pconn *p = (_pconn *)data;
-    assert(table != NULL);
-    debug(48, 3) ("pconnTimeout: FD %d %s\n", fd, hashKeyStr(&p->hash));
-    pconnRemoveFD(p, fd);
-    comm_close(fd);
+    for (int i = 0; i< nfds; i++) {
+        if (!comm_has_pending_read_callback(fds[i])) {
+            return fds[i];
+        }
+    }
+
+    return -1;
 }
 
-static void
-pconnRead(int fd, char *buf, size_t len, comm_err_t flag, int xerrno, void *data)
+void
+IdleConnList::read(int fd, char *buf, size_t len, comm_err_t flag, int xerrno, void *data)
 {
-
-    struct _pconn *p = (_pconn *)data;
-    assert(table != NULL);
-    /* Bail out early on COMM_ERR_CLOSING - close handlers will tidy up for us */
+    debug(48, 3) ("IdleConnList::read: %d bytes from FD %d\n", (int) len, fd);
 
     if (flag == COMM_ERR_CLOSING) {
+        /* Bail out early on COMM_ERR_CLOSING - close handlers will tidy up for us */
         return;
     }
 
-    debug(48, 3) ("pconnRead: %d bytes from FD %d, %s\n", (int) len, fd,
-                  hashKeyStr(&p->hash));
-    pconnRemoveFD(p, fd);
+    IdleConnList *list = (IdleConnList *) data;
+    list->removeFD(fd);	/* might delete list */
     comm_close(fd);
 }
 
-static void
-pconnHistDump(StoreEntry * e)
+void
+IdleConnList::timeout(int fd, void *data)
 {
-    int i;
-    storeAppendPrintf(e,
-                      "Client-side persistent connection counts:\n"
-                      "\n"
-                      "\treq/\n"
-                      "\tconn      count\n"
-                      "\t----  ---------\n");
+    debug(48, 3) ("IdleConnList::timeout: FD %d\n", fd);
+    IdleConnList *list = (IdleConnList *) data;
+    list->removeFD(fd);	/* might delete list */
+    comm_close(fd);
+}
 
-    for (i = 0; i < PCONN_HIST_SZ; i++) {
-        if (client_pconn_hist[i] == 0)
-            continue;
+/* ========== PconnPool PRIVATE FUNCTIONS ============================================ */
 
-        storeAppendPrintf(e, "\t%4d  %9d\n", i, client_pconn_hist[i]);
-    }
+const char *
+PconnPool::key(const char *host, u_short port, const char *domain)
+{
+    LOCAL_ARRAY(char, buf, SQUIDHOSTNAMELEN * 2 + 10);
+
+    if (domain)
+        snprintf(buf, SQUIDHOSTNAMELEN * 2 + 10, "%s:%d/%s", host, (int) port, domain);
+    else
+        snprintf(buf, SQUIDHOSTNAMELEN * 2 + 10, "%s:%d", host, (int) port);
+
+    return buf;
+}
 
+void
+PconnPool::dumpHist(StoreEntry * e)
+{
+    int i;
     storeAppendPrintf(e,
-                      "\n"
-                      "Server-side persistent connection counts:\n"
+                      "%s persistent connection counts:\n"
                       "\n"
                       "\treq/\n"
                       "\tconn      count\n"
-                      "\t----  ---------\n");
+                      "\t----  ---------\n",
+                      descr);
 
     for (i = 0; i < PCONN_HIST_SZ; i++) {
-        if (server_pconn_hist[i] == 0)
+        if (hist[i] == 0)
             continue;
 
-        storeAppendPrintf(e, "\t%4d  %9d\n", i, server_pconn_hist[i]);
+        storeAppendPrintf(e, "\t%4d  %9d\n", i, hist[i]);
     }
 }
 
-/* ========== PUBLIC FUNCTIONS ============================================ */
+/* ========== PconnPool PUBLIC FUNCTIONS ============================================ */
 
-
-void
-pconnInit(void)
+PconnPool::PconnPool(const char *aDescr) : table(NULL), descr(aDescr)
 {
     int i;
-    assert(table == NULL);
     table = hash_create((HASHCMP *) strcmp, 229, hash_string);
 
-    for (i = 0; i < PCONN_HIST_SZ; i++) {
-        client_pconn_hist[i] = 0;
-        server_pconn_hist[i] = 0;
-    }
+    for (i = 0; i < PCONN_HIST_SZ; i++)
+        hist[i] = 0;
 
-    pconn_fds_pool = MemPools::GetInstance().create("pconn_fds", PCONN_FDS_SZ * sizeof(int));
+    if (ThePconnModule == NULL)
+        ThePconnModule = new PconnModule;
 
-    cachemgrRegister("pconn",
-                     "Persistent Connection Utilization Histograms",
-                     pconnHistDump, 0, 1);
-    debug(48, 3) ("persistent connection module initialized\n");
+    ThePconnModule->add
+    (this);
 }
 
 void
-pconnPush(int fd, const char *host, u_short port, const char *domain)
+PconnPool::push(int fd, const char *host, u_short port, const char *domain)
 {
 
-    struct _pconn *p;
-    int *old;
-    LOCAL_ARRAY(char, key, SQUIDHOSTNAMELEN + 10);
+    IdleConnList *list;
+    const char *aKey;
     LOCAL_ARRAY(char, desc, FD_DESC_SZ);
 
     if (fdUsageHigh()) {
-        debug(48, 3) ("pconnPush: Not many unused FDs\n");
+        debug(48, 3) ("PconnPool::push: Not many unused FDs\n");
         comm_close(fd);
         return;
     } else if (shutting_down) {
         comm_close(fd);
         return;
     }
 
-    assert(table != NULL);
-    strncpy(key, pconnKey(host, port, domain), SQUIDHOSTNAMELEN + 10);
-
-    p = (struct _pconn *) hash_lookup(table, key);
-
-    if (p == NULL)
-        p = pconnNew(key);
+    aKey = key(host, port, domain);
 
-    if (p->nfds == p->nfds_alloc) {
-        debug(48, 3) ("pconnPush: growing FD array\n");
-        p->nfds_alloc <<= 1;
-        old = p->fds;
-        p->fds = (int *)xmalloc(p->nfds_alloc * sizeof(int));
-        xmemcpy(p->fds, old, p->nfds * sizeof(int));
+    list = (IdleConnList *) hash_lookup(table, aKey);
 
-        if (p->nfds == PCONN_FDS_SZ)
-            pconn_fds_pool->free(old);
-        else
-            xfree(old);
+    if (list == NULL) {
+        list = new IdleConnList(aKey, this);
+        debug(48, 3) ("pconnNew: adding %s\n", hashKeyStr(&list->hash));
+        hash_join(table, &list->hash);
     }
 
+    list->push(fd);
+
     assert(!comm_has_incomplete_write(fd));
-    p->fds[p->nfds++] = fd;
-    comm_read(fd, p->buf, BUFSIZ, pconnRead, p);
-    commSetTimeout(fd, Config.Timeout.pconn, pconnTimeout, p);
     snprintf(desc, FD_DESC_SZ, "%s idle connection", host);
     fd_note(fd, desc);
-    debug(48, 3) ("pconnPush: pushed FD %d for %s\n", fd, key);
+    debug(48, 3) ("PconnPool::push: pushed FD %d for %s\n", fd, aKey);
 }
 
 /*
  * return a pconn fd for host:port, or -1 if none are available
- * 
- * XXX this routine isn't terribly efficient - if there's a pending
- * read event (which signifies the fd will close in the next IO loop!)
- * we ignore the FD and move onto the next one. This means, as an example,
- * if we have a lot of FDs open to a very popular server and we get a bunch
- * of requests JUST as they timeout (say, it shuts down) we'll be wasting
- * quite a bit of CPU. Just keep it in mind.
  */
 int
-pconnPop(const char *host, u_short port, const char *domain)
+PconnPool::pop(const char *host, u_short port, const char *domain)
 {
+    IdleConnList *list;
+    const char * aKey = key(host, port, domain);
+    list = (IdleConnList *)hash_lookup(table, aKey);
 
-    struct _pconn *p;
-    hash_link *hptr;
-    int fd = -1;
-    LOCAL_ARRAY(char, key, SQUIDHOSTNAMELEN + 10);
-    assert(table != NULL);
-    strncpy(key, pconnKey(host, port, domain), SQUIDHOSTNAMELEN + 10);
-    hptr = (hash_link *)hash_lookup(table, key);
-
-    if (hptr != NULL) {
-
-        p = (struct _pconn *) hptr;
-        assert(p->nfds > 0);
-
-        for (int i = 0; i < p->nfds; i++) {
-            fd = p->fds[p->nfds - 1];
-            /* If there are pending read callbacks - we're about to close it, so don't issue it! */
-
-            if (!comm_has_pending_read_callback(fd)) {
-                pconnRemoveFD(p, fd);
-                comm_read_cancel(fd, pconnRead, p);
-                commSetTimeout(fd, -1, NULL, NULL);
-                return fd;
-            }
-        }
+    if (list == NULL)
+        return -1;
+
+    int fd = list->findUseableFD();
+
+    if (fd >= 0) {
+        list->clearHandlers(fd);
+        list->removeFD(fd);	/* might delete list */
     }
 
-    /* Nothing (valid!) found */
-    return -1;
+    return fd;
 }
 
 void
-pconnHistCount(int what, int i)
+PconnPool::unlinkList(IdleConnList *list) const
 {
-    if (i >= PCONN_HIST_SZ)
-        i = PCONN_HIST_SZ - 1;
-
-    /* what == 0 for client, 1 for server */
-    if (what == 0)
-        client_pconn_hist[i]++;
-    else if (what == 1)
-        server_pconn_hist[i]++;
-    else
-        assert(0);
+    hash_remove_link(table, &list->hash);
+}
+
+void
+PconnPool::count(int uses)
+{
+    if (uses >= PCONN_HIST_SZ)
+        uses = PCONN_HIST_SZ - 1;
+
+    hist[uses]++;
+}
+
+/* ========== PconnModule ============================================ */
+
+/*
+ * This simple class exists only for the cache manager
+ */
+
+PconnModule::PconnModule() : pools(NULL), poolCount(0)
+{
+    pools = (PconnPool **) xcalloc(MAX_NUM_PCONN_POOLS, sizeof(*pools));
+    cachemgrRegister("pconn",
+                     "Persistent Connection Utilization Histograms",
+                     PconnModuleDumpWrapper, 0, 1);
+    pconn_fds_pool = MemPools::GetInstance().create("pconn_fds", PCONN_FDS_SZ * sizeof(int));
+    debug(48, 0) ("persistent connection module initialized\n");
+}
+
+void
+
+PconnModule::add
+    (PconnPool *aPool)
+{
+    assert(poolCount < MAX_NUM_PCONN_POOLS);
+    *(pools+poolCount) = aPool;
+    poolCount++;
+}
+
+void
+PconnModule::dump(StoreEntry *e)
+{
+    int i;
+
+    for (i = 0; i < poolCount; i++) {
+        (*(pools+i))->dumpHist(e);
+    }
+}
+
+static void
+PconnModuleDumpWrapper(StoreEntry *e)
+{
+    ThePconnModule->dump(e);
 }
