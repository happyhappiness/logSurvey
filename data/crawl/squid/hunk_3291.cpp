     setbuf(stdout, NULL);
     setbuf(stderr, NULL);
 
-    while (1) {
-        /* Read whole line from standard input. Terminate on break. */
-        if (fgets(wstr, 255, stdin) == NULL)
-            break;
+    while (fgets(wstr, HELPER_INPUT_BUFFER, stdin) != NULL) {
 
         if (NULL == strchr(wstr, '\n')) {
             err = 1;
             continue;
         }
         if (err) {
-            fprintf(stderr, "Oversized message\n");
-            puts("ERR");
-            goto error;
+            SEND_ERR("Oversized message");
+            err = 0;
+            fflush(stdout);
+            continue;
         }
 
         if ((p = strchr(wstr, '\n')) != NULL)
