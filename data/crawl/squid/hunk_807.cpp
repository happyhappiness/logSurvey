     const int ruleId = ((treep && *treep) ? (*treep)->childrenCount() : 0) + 1;
     MemBuf ctxBuf;
     ctxBuf.init();
-    ctxBuf.Printf("%s#%d", directive, ruleId);
+    ctxBuf.appendf("%s#%d", directive, ruleId);
     ctxBuf.terminate();
 
     Acl::AndNode *rule = new Acl::AndNode;
