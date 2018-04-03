 
         if (head->flags.ignore_private)
             storeAppendPrintf(entry, " ignore-private");
-
-        if (head->flags.ignore_auth)
-            storeAppendPrintf(entry, " ignore-auth");
-
 #endif
 
         storeAppendPrintf(entry, "\n");
