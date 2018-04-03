     fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
 #endif
     nas_ipaddr = ntohl(salocal.sin_addr.s_addr);
-    while (fgets(authstring, MAXLINE, stdin) != NULL) {
+    while (fgets(buf, HELPER_INPUT_BUFFER, stdin) != NULL) {
         char *end;
         /* protect me form to long lines */
-        if ((end = strchr(authstring, '\n')) == NULL) {
+        if ((end = strchr(buf, '\n')) == NULL) {
             err = 1;
             continue;
         }
         if (err) {
-            printf("ERR\n");
+            SEND_ERR("");
             err = 0;
             continue;
         }
-        if (strlen(authstring) > MAXLINE) {
-            printf("ERR\n");
+        if (strlen(buf) > HELPER_INPUT_BUFFER) {
+            SEND_ERR("");
             continue;
         }
         /* Strip off the trailing newline */
         *end = '\0';
 
         /* Parse out the username and password */
-        ptr = authstring;
+        ptr = buf;
         while (isspace(*ptr))
             ptr++;
         if ((end = strchr(ptr, ' ')) == NULL) {
-            printf("ERR\n");	/* No password */
+            SEND_ERR("No password");
             continue;
         }
         *end = '\0';
