     storeAppendPrintf(entry, "\n");
 
     storeAppendPrintf(entry, "%s basic realm %s\n", name, basicAuthRealm);
-    storeAppendPrintf(entry, "%s basic children %d\n", name, authenticateChildren);
+    storeAppendPrintf(entry, "%s basic children %d startup=%d idle=%d\n", name, authenticateChildren.n_max, authenticateChildren.n_startup, authenticateChildren.n_idle);
     storeAppendPrintf(entry, "%s basic concurrency %d\n", name, authenticateConcurrency);
     storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
     storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
 }
 
-AuthBasicConfig::AuthBasicConfig()
+AuthBasicConfig::AuthBasicConfig() : authenticateChildren(20,0,1,1)
 {
     /* TODO: move into initialisation list */
-    authenticateChildren = 5;
     credentialsTTL = 2 * 60 * 60;	/* two hours */
     basicAuthRealm = xstrdup("Squid proxy-caching web server");
 }
