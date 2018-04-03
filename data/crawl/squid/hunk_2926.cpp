  */
 
 #include "CacheManager.h"
+#include "mgr/Registration.h"
 #include "squid.h"
 
-static CacheManager *cm=0;
-
-CacheManager::CacheManager()
-{
-}
-
-void
-CacheManager::registerAction(char const * action, char const * desc, OBJH * handler, int pw_req_flag, int atomic)
+Mgr::Action::Pointer
+CacheManager::createNamedAction(char const* action)
 {
-    return;
+    fatal ("Not implemented");
+    return NULL;
 }
 
 void
-CacheManager::registerAction(CacheManagerAction *anAction)
+CacheManager::Start(int fd, HttpRequest * request, StoreEntry * entry)
 {
     return;
 }
 
-CacheManagerAction *
-CacheManager::findAction(char const * action)
+CacheManager*
+CacheManager::GetInstance(void)
 {
-    return 0;
+    static CacheManager *instance = 0;
+    if (!instance)
+        instance = new CacheManager();
+    return instance;
 }
 
 void
-CacheManager::Start(int fd, HttpRequest * request, StoreEntry * entry)
+Mgr::RegisterAction(char const*, char const*, OBJH, int, int)
 {
-    return;
 }
 
-CacheManager*
-CacheManager::GetInstance(void)
+void
+Mgr::RegisterAction(char const * action, char const * desc,
+    Mgr::ClassActionCreationHandler *handler,
+    int pw_req_flag, int atomic)
 {
-    if (!cm)
-        cm=new CacheManager();
-    return cm;
 }
-
