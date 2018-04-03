     if (!authenticateProgram)
         return false; // not configured
 
-    const char *type = scheme->type();
+    const char *schemeType = scheme->type();
 
     wordlist *list = authenticateProgram;
-    storeAppendPrintf(entry, "%s %s", name, type);
+    storeAppendPrintf(entry, "%s %s", name, schemeType);
     while (list != NULL) {
         storeAppendPrintf(entry, " %s", list->key);
         list = list->next;
     }
     storeAppendPrintf(entry, "\n");
 
-    storeAppendPrintf(entry, "%s %s realm " SQUIDSBUFPH "\n", name, type, SQUIDSBUFPRINT(realm));
+    storeAppendPrintf(entry, "%s %s realm " SQUIDSBUFPH "\n", name, schemeType, SQUIDSBUFPRINT(realm));
 
     storeAppendPrintf(entry, "%s %s children %d startup=%d idle=%d concurrency=%d\n",
-                      name, type,
+                      name, schemeType,
                       authenticateChildren.n_max, authenticateChildren.n_startup,
                       authenticateChildren.n_idle, authenticateChildren.concurrency);
 
     if (keyExtrasLine.size() > 0) // default is none
-        storeAppendPrintf(entry, "%s %s key_extras \"%s\"\n", name, type, keyExtrasLine.termedBuf());
+        storeAppendPrintf(entry, "%s %s key_extras \"%s\"\n", name, schemeType, keyExtrasLine.termedBuf());
 
     if (!keep_alive) // default is on
-        storeAppendPrintf(entry, "%s %s keep_alive off\n", name, type);
+        storeAppendPrintf(entry, "%s %s keep_alive off\n", name, schemeType);
 
     if (utf8) // default is off
-        storeAppendPrintf(entry, "%s %s utf8 on\n", name, type);
+        storeAppendPrintf(entry, "%s %s utf8 on\n", name, schemeType);
 
     return true;
 }