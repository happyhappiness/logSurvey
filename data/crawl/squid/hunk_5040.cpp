     }
 
     if (!t)
-        fatal("aclParseUserMaxIP: Malformed ACL\n");
+        return;
 
     maximum = atoi(t);
 
