     return NULL;
 }
 
-ACL *
-ACL::clone()const
+void
+ACL::Initialize()
 {
-    fatal ("Cannot clone base class");
-    return NULL;
+    acl *a = Config.aclList;
+    debug(53, 3) ("ACL::Initialize\n");
+
+    while (a) {
+        a->prepareForUse();
+        a = a->next;
+    }
 }
