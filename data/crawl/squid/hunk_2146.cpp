     fatal("not implemented");
 }
 
+// move this into [non-shared] memory cache class when we have one
+/// whether e should be kept in local RAM for possible future caching
+bool
+StoreController::keepForLocalMemoryCache(const StoreEntry &e) const
+{
+    if (!e.memoryCachable())
+        return false;
+
+    // does the current and expected size obey memory caching limits?
+    assert(e.mem_obj);
+    const int64_t loadedSize = e.mem_obj->endOffset();
+    const int64_t expectedSize = e.mem_obj->expectedReplySize(); // may be < 0
+    const int64_t ramSize = max(loadedSize, expectedSize);
+    const int64_t ramLimit = min(
+                                 static_cast<int64_t>(Config.memMaxSize),
+                                 static_cast<int64_t>(Config.Store.maxInMemObjSize));
+    return ramSize <= ramLimit;
+}
+
+void
+StoreController::maybeTrimMemory(StoreEntry &e, const bool preserveSwappable)
+{
+    bool keepInLocalMemory = false;
+    if (memStore)
+        keepInLocalMemory = memStore->keepInLocalMemory(e);
+    else
+        keepInLocalMemory = keepForLocalMemoryCache(e);
+
+    debugs(20, 7, HERE << "keepInLocalMemory: " << keepInLocalMemory);
+
+    if (!keepInLocalMemory)
+        e.trimMemory(preserveSwappable);
+}
+
 void
 StoreController::handleIdleEntry(StoreEntry &e)
 {
