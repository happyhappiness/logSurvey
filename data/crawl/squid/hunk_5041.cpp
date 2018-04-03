     if (!new_acl)
         return;
 
-    if (!A->valid()) {
-        debug(28, 0) ("aclParseAclLine: IGNORING invalid ACL: %s\n",
+    if (A->empty()) {
+        debug(28, 0) ("Warning: empty ACL: %s\n",
                       A->cfgline);
-        delete A;
-        /* Do we need this? */
-        A = NULL;
-        return;
+    }
+
+    if (!A->valid()) {
+        fatalf("ERROR: Invalid ACL: %s\n",
+               A->cfgline);
     }
 
     /* append */
