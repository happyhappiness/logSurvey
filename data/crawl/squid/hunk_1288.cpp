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
+    if (!Auth::Config::dump(entry, name, scheme))
+        return false;
 
-    while (list != NULL) {
-        storeAppendPrintf(entry, " %s", list->key);
-        list = list->next;
-    }
-
-    storeAppendPrintf(entry, "\n%s %s realm %s\n%s %s children %d startup=%d idle=%d concurrency=%d\n%s %s nonce_max_count %d\n%s %s nonce_max_duration %d seconds\n%s %s nonce_garbage_interval %d seconds\n",
-                      name, "digest", digestAuthRealm,
-                      name, "digest", authenticateChildren.n_max, authenticateChildren.n_startup, authenticateChildren.n_idle, authenticateChildren.concurrency,
+    storeAppendPrintf(entry, "%s %s nonce_max_count %d\n%s %s nonce_max_duration %d seconds\n%s %s nonce_garbage_interval %d seconds\n",
                       name, "digest", noncemaxuses,
                       name, "digest", (int) noncemaxduration,
                       name, "digest", (int) nonceGCInterval);
-    Auth::Config::dump(entry, name, scheme);
+    storeAppendPrintf(entry, "%s digest utf8 %s\n", name, utf8 ? "on" : "off");
+    return true;
 }
 
 bool
