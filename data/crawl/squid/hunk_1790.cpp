 
     while (ae != NULL) {
         debugs(3, 3, "dump_acl: " << name << " " << ae->name);
-        storeAppendPrintf(entry, "%s %s %s ",
+        storeAppendPrintf(entry, "%s %s %s %s ",
                           name,
                           ae->name,
-                          ae->typeString());
+                          ae->typeString(),
+                          ae->flags.flagsStr());
         v = w = ae->dump();
 
         while (v != NULL) {
