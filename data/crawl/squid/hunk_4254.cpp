 #include "CacheManager.h"
 #include "squid.h"
 
+static CacheManager *cm=0;
+
 CacheManager::CacheManager()
 {
 }
 
 void
 CacheManager::registerAction(char const * action, char const * desc, OBJH * handler, int pw_req_flag, int atomic)
 {
-	fatal("Not implemented");
+    return;
 }
 
 void
 CacheManager::registerAction(CacheManagerAction *anAction)
 {
-	fatal("Not implemented");
+    return;
 }
 
 CacheManagerAction *
 CacheManager::findAction(char const * action)
 {
-	fatal("Not implemented");
-	return 0; //notreached
+    return 0;
 }
 
 void
 CacheManager::Start(int fd, HttpRequest * request, StoreEntry * entry)
 {
-	fatal("Not implemented");
+    return;
 }
 
 CacheManager*
-CacheManager::GetInstance()
+CacheManager::GetInstance(void)
 {
-	fatal("Not implemented");
-	return 0; //notreached
+    if (!cm)
+        cm=new CacheManager();
+    return cm;
 }
 
