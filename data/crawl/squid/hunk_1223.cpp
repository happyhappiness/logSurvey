     }
 
     if (r == -1) {
-        return parseHttpRequestAbort(csd, "error:invalid-request");
+        return csd->abortRequestParsing("error:invalid-request");
     }
 
     /* Request line is valid here .. */
