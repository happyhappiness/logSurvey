     BOOL Done = FALSE;
 
 try_again:
-    if (fgets(buf, BUFFER_SIZE, stdin) == NULL)
+    if (fgets(buf, HELPER_INPUT_BUFFER, stdin))
         return 0;
 
-    c = memchr(buf, '\n', BUFFER_SIZE);		/* safer against overrun than strchr */
+    c = memchr(buf, '\n', HELPER_INPUT_BUFFER);		/* safer against overrun than strchr */
     if (c) {
         if (oversized) {
-            helperfail("illegal request received");
-            fprintf(stderr, "Illegal request received: '%s'\n", buf);
+            SEND("BH illegal request received");
+            fprintf(stderr, "ERROR: Illegal request received: '%s'\n", buf);
             return 1;
         }
         *c = '\0';
