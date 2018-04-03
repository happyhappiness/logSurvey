     char *t = strtokFile();
 
     if (!t)
-        fatal("aclParseUserMaxIP: Malformed ACL\n");
+        return;
 
     debug(28, 5) ("aclParseUserMaxIP: First token is %s\n", t);
 
