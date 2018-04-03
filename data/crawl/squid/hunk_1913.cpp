         fprintf(stderr, "FATAL: %s: %s\n", passwdfile, xstrerror());
         exit(1);
     }
-    while (fgets(buf, 8192, f) != NULL) {
+    unsigned int lineCount = 0;
+    buf[sizeof(buf)] = '\0';
+    while (fgets(buf, sizeof(buf)-1, f) != NULL) {
+        ++lineCount;
         if ((buf[0] == '#') || (buf[0] == ' ') || (buf[0] == '\t') ||
                 (buf[0] == '\n'))
             continue;
         user = strtok(buf, ":\n\r");
+        if (user == NULL) {
+            fprintf(stderr, "ERROR: Missing user name at %s line %d\n", passwdfile, lineCount);
+            continue;
+        }
         passwd = strtok(NULL, ":\n\r");
         if ((strlen(user) > 0) && passwd) {
             u = static_cast<user_data*>(xmalloc(sizeof(*u)));