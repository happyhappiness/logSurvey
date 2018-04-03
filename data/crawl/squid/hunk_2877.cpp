     return;
 }
 
+CacheManager* CacheManager::instance=0;
+
 CacheManager*
-CacheManager::GetInstance(void)
+CacheManager::GetInstance()
 {
-    static CacheManager *instance = 0;
-    if (!instance)
-        instance = new CacheManager();
+    fatal("Not implemented");
     return instance;
 }
 