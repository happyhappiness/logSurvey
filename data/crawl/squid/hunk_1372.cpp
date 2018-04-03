         wordlistDestroy(&authenticateProgram);
 }
 
-void
-Auth::Basic::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme)
+bool
+Auth::Basic::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme) const
 {
-    wordlist *list = authenticateProgram;
-    storeAppendPrintf(entry, "%s %s", name, "basic");
-
-    while (list != NULL) {
-        storeAppendPrintf(entry, " %s", list->key);
-        list = list->next;
-    }
-
-    storeAppendPrintf(entry, "\n");
+    if (!Auth::Config::dump(entry, name, scheme))
+        return false; // not configured
 
     storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
     storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
-    Auth::Config::dump(entry, name, scheme);
+    storeAppendPrintf(entry, "%s basic utf8 %s\n", name, utf8 ? "on" : "off");
+    return true;
 }
 
 Auth::Basic::Config::Config() :
