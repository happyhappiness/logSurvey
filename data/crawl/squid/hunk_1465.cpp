 void
 Auth::Config::dump(StoreEntry *entry, const char *name, Auth::Config *scheme)
 {
+    storeAppendPrintf(entry, "%s %s children %d startup=%d idle=%d concurrency=%d\n",
+                      name, scheme->type(),
+                      authenticateChildren.n_max, authenticateChildren.n_startup,
+                      authenticateChildren.n_idle, authenticateChildren.concurrency);
+
     if (keyExtrasLine.size() > 0)
         storeAppendPrintf(entry, "%s %s key_extras \"%s\"\n", name, scheme->type(), keyExtrasLine.termedBuf());
 }
