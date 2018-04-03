     /* NP: dynamic helper restart will ensure they start up again as needed. */
 }
 
-void
-Auth::Digest::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme)
+bool
+Auth::Digest::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme) const
 {
-    wordlist *list = authenticateProgram;
-    debugs(29, 9, "Dumping configuration");
-    storeAppendPrintf(entry, "%s %s", name, "digest");
-
-    while (list != NULL) {
-        storeAppendPrintf(entry, " %s", list->key);
-        list = list->next;
-    }
+    if (!Auth::Config::dump(entry, name, scheme))
+        return false;
 
-    storeAppendPrintf(entry, "\n%s %s nonce_max_count %d\n%s %s nonce_max_duration %d seconds\n%s %s nonce_garbage_interval %d seconds\n",
+    storeAppendPrintf(entry, "%s %s nonce_max_count %d\n%s %s nonce_max_duration %d seconds\n%s %s nonce_garbage_interval %d seconds\n",
                       name, "digest", noncemaxuses,
                       name, "digest", (int) noncemaxduration,
                       name, "digest", (int) nonceGCInterval);
-    Auth::Config::dump(entry, name, scheme);
+    storeAppendPrintf(entry, "%s digest utf8 %s\n", name, utf8 ? "on" : "off");
+    return true;
 }
 
 bool
