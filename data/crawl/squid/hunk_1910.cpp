         fprintf(stderr, "digest_file_auth: cannot create hash table\n");
         exit(1);
     }
-    f = fopen(passwordFile, "r");
-    while (fgets(buf, 8192, f) != NULL) {
+    FILE *f = fopen(passwordFile, "r");
+    if (!f) {
+        fprintf(stderr, "digest_file_auth: cannot open password file: %s\n", xstrerror());
+        exit(1);
+    }
+    unsigned int lineCount = 0;
+    while (fgets(buf, sizeof(buf), f) != NULL) {
+        ++lineCount;
         if ((buf[0] == '#') || (buf[0] == ' ') || (buf[0] == '\t') ||
                 (buf[0] == '\n'))
             continue;
         user = strtok(buf, ":\n");
+        if (!user) {
+            fprintf(stderr, "digest_file_auth: missing user name at line %u in '%'\n", lineCount, passwordFile);
+            continue;
+        }
         realm = strtok(NULL, ":\n");
         passwd = strtok(NULL, ":\n");
         if (!passwd) {