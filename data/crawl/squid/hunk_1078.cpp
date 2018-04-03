     static char cred[SSP_MAX_CRED_LEN + 1];
     BOOL Done = FALSE;
 
-try_again:
-    if (fgets(buf, HELPER_INPUT_BUFFER, stdin))
-        return 0;
+    do {
+        if (fgets(buf, HELPER_INPUT_BUFFER, stdin))
+            return 0;
 
-    c = static_cast<char*>(memchr(buf, '\n', HELPER_INPUT_BUFFER));
-    if (c) {
-        if (oversized) {
-            SEND("BH illegal request received");
-            fprintf(stderr, "ERROR: Illegal request received: '%s'\n", buf);
-            return 1;
+        c = static_cast<char*>(memchr(buf, '\n', HELPER_INPUT_BUFFER));
+        if (c) {
+            if (oversized) {
+                SEND("BH illegal request received");
+                fprintf(stderr, "ERROR: Illegal request received: '%s'\n", buf);
+                return 1;
+            }
+            *c = '\0';
+        } else {
+            fprintf(stderr, "No newline in '%s'\n", buf);
+            oversized = 1;
         }
-        *c = '\0';
-    } else {
-        fprintf(stderr, "No newline in '%s'\n", buf);
-        oversized = 1;
-        goto try_again;
-    }
+    } while (!c);
 
     if ((strlen(buf) > 3) && Negotiate_packet_debug_enabled) {
-        decodedLen = base64_decode(decoded, sizeof(decoded), buf+3);
+        if (!token_decode(&decodedLen, decoded, buf+3))
+            return 1;
         strncpy(helper_command, buf, 2);
         debug("Got '%s' from Squid with data:\n", helper_command);
         hex_dump(reinterpret_cast<unsigned char*>(decoded), decodedLen);
