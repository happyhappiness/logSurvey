     return s;
 }
 
-int
-parseConfigFile(const char *file_name, CacheManager & manager)
+static int
+parseManyConfigFiles(char* files, int depth)
+{
+    int error_count = 0;
+    char* tmp = files;
+    char* file = strtok(tmp, w_space);
+    while (file != NULL) {
+        tmp += strlen(file) +1;
+        error_count += parseOneConfigFile(file, depth);
+        file = strtok(tmp, w_space);
+    }
+    return error_count;
+}
+
+static int
+parseOneConfigFile(const char *file_name, unsigned int depth)
 {
     FILE *fp = NULL;
+    const char *orig_cfg_filename = cfg_filename;
+    const int orig_config_lineno = config_lineno;
     char *token = NULL;
     char *tmp_line = NULL;
     int tmp_line_len = 0;
     int err_count = 0;
     int is_pipe = 0;
-    configFreeMemory();
-    default_all();
+
+    debugs(3, 1, "Processing Configuration File: " << file_name << " (depth " << depth << ")");
+    if (depth > 16) {
+        fatalf("WARNING: can't include %s: includes are nested too deeply (>16)!\n", file_name);
+        return 1;
+    }
 
     if (file_name[0] == '!' || file_name[0] == '|') {
         fp = popen(file_name + 1, "r");
