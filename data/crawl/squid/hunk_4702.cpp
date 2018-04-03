         return;
 
     if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
-        ftpState->transactionAbort();
+        ftpState->abortTransaction("entry aborted during control reply read");
         return;
     }
 
