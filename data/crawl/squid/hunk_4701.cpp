 #endif
 
     if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
-        transactionAbort();
+        abortTransaction("entry aborted during dataRead");
         return;
     }
 
