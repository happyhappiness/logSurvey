         err->detailError(ERR_DETAIL_ICAP_RESPMOD_EARLY);
         fwd->fail(err);
         fwd->dontRetry(true);
-        abortTransaction("adaptation failure with an empty entry");
+        abortAll("adaptation failure with an empty entry");
         return true; // handled
     }
 
