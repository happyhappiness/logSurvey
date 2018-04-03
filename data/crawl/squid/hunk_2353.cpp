 /*
  * STUB file for the pconn.cc API
- * Functions here are inactive.
  */
 #include "config.h"
 #include "pconn.h"
 #include "comm/Connection.h"
 
-IdleConnList::IdleConnList(const char *key, PconnPool *parent)
-{
-    fatal("pconn.cc required");
-}
-
-IdleConnList::~IdleConnList()
-{
-    fatal("pconn.cc required");
-}
-
-void
-IdleConnList::push(const Comm::ConnectionPointer &conn)
-{
-    fatal("pconn.cc required");
-}
-
-Comm::ConnectionPointer
-IdleConnList::findUseable(const Comm::ConnectionPointer &key)
-{
-    fatal("pconn.cc required");
-    return Comm::ConnectionPointer();
-}
-
-void
-IdleConnList::clearHandlers(const Comm::ConnectionPointer &conn)
-{
-    fatal("pconn.cc required");
-}
-
-PconnPool::PconnPool(const char *)
-{
-    fatal("pconn.cc required");
-}
-
-PconnPool::~PconnPool()
-{
-    fatal("pconn.cc required");
-}
-
-void
-PconnPool::moduleInit()
-{
-    fatal("pconn.cc required");
-}
-
-void
-PconnPool::push(const Comm::ConnectionPointer &serverConn, const char *domain)
-{
-    fatal("pconn.cc required");
-}
-
-Comm::ConnectionPointer
-PconnPool::pop(const Comm::ConnectionPointer &destLink, const char *domain, bool retriable)
-{
-    fatal("pconn.cc required");
-    return Comm::ConnectionPointer();
-}
-
-void
-PconnPool::count(int uses)
-{
-    fatal("pconn.cc required");
-}
-
-void
-PconnPool::noteUses(int)
-{
-    fatal("pconn.cc required");
-}
-
-void
-PconnPool::dumpHist(StoreEntry *e) const
-{
-    fatal("pconn.cc required");
-}
-
-void
-PconnPool::dumpHash(StoreEntry *e) const
-{
-    fatal("pconn.cc required");
-}
-
-void
-PconnPool::unlinkList(IdleConnList *list)
-{
-    fatal("pconn.cc required");
-}
-
-PconnModule *
-PconnModule::GetInstance()
-{
-    fatal("pconn.cc required");
-    return NULL;
-}
-
-void
-PconnModule::DumpWrapper(StoreEntry *e)
-{
-    fatal("pconn.cc required");
-}
-
-PconnModule::PconnModule()
-{
-    fatal("pconn.cc required");
-}
-
-void
-PconnModule::registerWithCacheManager(void)
-{
-    fatal("pconn.cc required");
-}
-
-void
-PconnModule::add(PconnPool *)
-{
-    fatal("pconn.cc required");
-}
-
-void
-PconnModule::dump(StoreEntry *)
-{
-    fatal("pconn.cc required");
-}
+#define STUB_API "pconn.cc"
+#include "tests/STUB.h"
+
+IdleConnList::IdleConnList(const char *key, PconnPool *parent) STUB
+IdleConnList::~IdleConnList() STUB
+void IdleConnList::push(const Comm::ConnectionPointer &conn) STUB
+Comm::ConnectionPointer IdleConnList::findUseable(const Comm::ConnectionPointer &key) STUB_RETVAL(Comm::ConnectionPointer())
+void IdleConnList::clearHandlers(const Comm::ConnectionPointer &conn) STUB
+PconnPool::PconnPool(const char *) STUB
+PconnPool::~PconnPool() STUB
+void PconnPool::moduleInit() STUB
+void PconnPool::push(const Comm::ConnectionPointer &serverConn, const char *domain) STUB
+Comm::ConnectionPointer PconnPool::pop(const Comm::ConnectionPointer &destLink, const char *domain, bool retriable) STUB_RETVAL(Comm::ConnectionPointer())
+void PconnPool::count(int uses) STUB
+void PconnPool::noteUses(int) STUB
+void PconnPool::dumpHist(StoreEntry *e) const STUB
+void PconnPool::dumpHash(StoreEntry *e) const STUB
+void PconnPool::unlinkList(IdleConnList *list) STUB
+PconnModule * PconnModule::GetInstance() STUB_RETVAL(NULL)
+void PconnModule::DumpWrapper(StoreEntry *e) STUB
+PconnModule::PconnModule() STUB
+void PconnModule::registerWithCacheManager(void) STUB
+void PconnModule::add(PconnPool *) STUB
+void PconnModule::dump(StoreEntry *) STUB
