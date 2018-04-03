     int i = 0;
 
     for (t = s; *t != '\0'; ++t) {
-        if (i > HELPER_INPUT_BUFFER-2) {
+        /*
+         * NP: The shell escaping permits 'i' to jump up to 2 octets per loop,
+         *     so ensure we have at least 3 free.
+         */
+        if (i > HELPER_INPUT_BUFFER-3) {
             buf[i] = '\0';
             (void) fputs(buf, p);
             i = 0;
