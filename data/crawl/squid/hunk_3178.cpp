 
     init_db();
 
-    while (fgets(request, sizeof(request), stdin)) {
-        const char *user_key, *detail;
-        char *lastdetail;
+    while (fgets(request, HELPER_INPUT_BUFFER, stdin)) {
         int action = 0;
-        user_key = strtok(request, " \n");
-        detail = strtok(NULL, "\n");
-        lastdetail = strrchr(detail, ' ');
+        const char *user_key = strtok(request, " \n");
+        const char *detail = strtok(NULL, "\n");
+        const char *lastdetail = strrchr(detail, ' ');
+        size_t detail_len;
         if (lastdetail) {
             if (strcmp(lastdetail, " LOGIN") == 0) {
-                *lastdetail++ = '\0';
                 action = 1;
+                detail_len = (size_t)(lastdetail-detail);
             } else if (strcmp(lastdetail, " LOGOUT") == 0) {
                 action = -1;
-                *lastdetail++ = '\0';
+                detail_len = (size_t)(lastdetail-detail);
             }
         }
         if (action == -1) {
-            session_logout(detail);
+            session_logout(detail, detail_len);
             printf("%s OK message=\"Bye\"\n", user_key);
         } else if (action == 1) {
-            session_login(detail);
+            session_login(detail, detail_len);
             printf("%s OK message=\"Welcome\"\n", user_key);
-        } else if (session_active(detail)) {
-            session_login(detail);
+        } else if (session_active(detail, detail_len)) {
+            session_login(detail, detail_len);
             printf("%s OK\n", user_key);
         } else if (default_action == 1) {
-            session_login(detail);
+            session_login(detail, detail_len);
             printf("%s ERR message=\"Welcome\"\n", user_key);
         } else {
             printf("%s ERR message=\"No session available\"\n", user_key);
