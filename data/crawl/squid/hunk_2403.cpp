     while (fgets(request, HELPER_INPUT_BUFFER, stdin)) {
         int action = 0;
         const char *channel_id = strtok(request, " ");
-        const char *detail = strtok(NULL, "\n");
+        char *detail = strtok(NULL, "\n");
         if (detail == NULL) {
             // Only 1 paramater supplied. We are expecting at least 2 (including the channel ID)
             fprintf(stderr, "FATAL: %s is concurrent and requires the concurrency option to be specified.\n", program_name);
+            shutdown_db();
             exit(1);
         }
-        const char *lastdetail = strrchr(detail, ' ');
+        char *lastdetail = strrchr(detail, ' ');
         size_t detail_len = strlen(detail);
         if (lastdetail) {
             if (strcmp(lastdetail, " LOGIN") == 0) {
                 action = 1;
                 detail_len = (size_t)(lastdetail-detail);
+                *lastdetail = '\0';
             } else if (strcmp(lastdetail, " LOGOUT") == 0) {
                 action = -1;
                 detail_len = (size_t)(lastdetail-detail);
+                *lastdetail = '\0';
             }
         }
         if (action == -1) {
