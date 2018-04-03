     debugs(29, DBG_IMPORTANT, "Reconfigure: NTLM authentication configuration cleared.");
 }
 
-void
-Auth::Ntlm::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme)
+bool
+Auth::Ntlm::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme) const
 {
-    wordlist *list = authenticateProgram;
-    storeAppendPrintf(entry, "%s %s", name, "ntlm");
-
-    while (list != NULL) {
-        storeAppendPrintf(entry, " %s", list->key);
-        list = list->next;
-    }
+    if (!Auth::Config::dump(entry, name, scheme))
+        return false;
 
-    storeAppendPrintf(entry, "\n%s %s keep_alive %s\n", name, "ntlm", keep_alive ? "on" : "off");
-    Auth::Config::dump(entry, name, scheme);
+    storeAppendPrintf(entry, "%s ntlm keep_alive %s\n", name, keep_alive ? "on" : "off");
+    return true;
 }
 
 Auth::Ntlm::Config::Config() : keep_alive(1)
