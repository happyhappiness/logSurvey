     disableBypass("already started to bypass");
 
     Must(!isRetriable); // or we should not be bypassing
+    // TODO: should the same be enforced for isRepeatable? Check icap_repeat??
 
     prepEchoing();
 
