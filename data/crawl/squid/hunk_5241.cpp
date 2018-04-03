         list = list->next;
     }
 
-    storeAppendPrintf(entry, "\n%s %s realm %s\n%s %s children %d\n%s %s credentialsttl %d seconds\n",
-                      name, "basic", config->basicAuthRealm,
-                      name, "basic", config->authenticateChildren,
-                      name, "basic", (int) config->credentialsTTL);
+    storeAppendPrintf(entry, "\n");
+
+    storeAppendPrintf(entry, "%s basic realm %s\n", name, config->basicAuthRealm);
+    storeAppendPrintf(entry, "%s basic children %d\n", name, config->authenticateChildren);
+    storeAppendPrintf(entry, "%s basic concurrency %d\n", name, config->authenticateConcurrency);
+    storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) config->credentialsTTL);
 
 }
 
