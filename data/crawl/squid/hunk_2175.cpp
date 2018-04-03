     }
 
     if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
-        // TODO: should we call abortTransaction() here?
+        abortTransaction("store entry aborted while reading reply");
         return;
     }
 
