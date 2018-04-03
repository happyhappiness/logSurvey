         list = list->next;
     }
 
-    storeAppendPrintf(entry, "\n%s negotiate children %d startup=%d idle=%d concurrency=%d\n",
-                      name, authenticateChildren.n_max, authenticateChildren.n_startup, authenticateChildren.n_idle, authenticateChildren.concurrency);
-    storeAppendPrintf(entry, "%s %s keep_alive %s\n", name, "negotiate", keep_alive ? "on" : "off");
+    storeAppendPrintf(entry, "\n%s %s keep_alive %s\n", name, "negotiate", keep_alive ? "on" : "off");
     Auth::Config::dump(entry, name, scheme);
 }
 
