     }
 
     if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
-        maybeReadVirginBody();
+        // TODO: should we call abortTransaction() here?
         return;
     }
 