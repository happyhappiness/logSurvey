     storeAppendPrintf(entry, "\n");
 
     storeAppendPrintf(entry, "%s basic realm %s\n", name, basicAuthRealm);
-    storeAppendPrintf(entry, "%s basic children %d startup=%d idle=%d\n", name, authenticateChildren.n_max, authenticateChildren.n_startup, authenticateChildren.n_idle);
-    storeAppendPrintf(entry, "%s basic concurrency %d\n", name, authenticateConcurrency);
+    storeAppendPrintf(entry, "%s basic children %d startup=%d idle=%d concurrency=%d\n", name, authenticateChildren.n_max, authenticateChildren.n_startup, authenticateChildren.n_idle, authenticateChildren.concurrency);
     storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
     storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
 }
