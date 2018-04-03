             else
                 RFCNB_errno = RFCNBE_BadRead;
             RFCNB_saved_errno = errno;
-            return(RFCNBE_Bad);
+            return (RFCNBE_Bad);
 
         }
-
         /* Now we check out what we got */
 
-        if (read_len == 0) { /* Connection closed, send back eof?  */
+        if (read_len == 0) {    /* Connection closed, send back eof?  */
 
 #ifdef RFCNB_DEBUG
             fprintf(stderr, "Connection closed reading\n");
