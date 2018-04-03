     if (!entry->isEmpty()) { // too late to block (should not really happen)
         if (request)
             request->detailError(ERR_ICAP_FAILURE, ERR_DETAIL_RESPMOD_BLOCK_LATE);
-        abortTransaction("late adaptation block");
+        abortAll("late adaptation block");
         return;
     }
 
