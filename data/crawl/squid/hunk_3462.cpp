         if (node->grace)
             storeAppendPrintf(sentry, " grace=%d", node->grace);
 
-        if (node->children != DEFAULT_EXTERNAL_ACL_CHILDREN)
-            storeAppendPrintf(sentry, " children=%d", node->children);
+        if (node->children.n_max != DEFAULT_EXTERNAL_ACL_CHILDREN)
+            storeAppendPrintf(sentry, " children-max=%d", node->children.n_max);
 
-        if (node->concurrency)
-            storeAppendPrintf(sentry, " concurrency=%d", node->concurrency);
+        if (node->children.n_startup != 1)
+            storeAppendPrintf(sentry, " children-startup=%d", node->children.n_startup);
+
+        if (node->children.n_idle != (node->children.n_max + node->children.n_startup) )
+            storeAppendPrintf(sentry, " children-idle=%d", node->children.n_idle);
+
+        if (node->children.concurrency)
+            storeAppendPrintf(sentry, " concurrency=%d", node->children.concurrency);
 
         if (node->cache)
             storeAppendPrintf(sentry, " cache=%d", node->cache_size);
