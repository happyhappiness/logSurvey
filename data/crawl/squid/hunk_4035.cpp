     if (!startedAdaptation) {
         // handle start failure for an essential ICAP service
         ErrorState *err = errorCon(ERR_ICAP_FAILURE,
-            HTTP_INTERNAL_SERVER_ERROR, originalRequest());
+                                   HTTP_INTERNAL_SERVER_ERROR, originalRequest());
         err->xerrno = errno;
         errorAppendEntry(entry, err);
         abortTransaction("ICAP start failure");
