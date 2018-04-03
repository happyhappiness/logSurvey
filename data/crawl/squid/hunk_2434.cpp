 
     while (fgets(request, HELPER_INPUT_BUFFER, stdin)) {
         int action = 0;
-        const char *user_key = strtok(request, " \n");
+        const char *channel_id = strtok(request, " ");
         const char *detail = strtok(NULL, "\n");
+        if (detail == NULL) {
+            // Only 1 paramater supplied. We are expecting at least 2 (including the channel ID)
+            fprintf(stderr, "FATAL: %s is concurrent and requires the concurrency option to be specified.\n", program_name);
+            exit(1);
+        }
         const char *lastdetail = strrchr(detail, ' ');
         size_t detail_len = strlen(detail);
         if (lastdetail) {
