   return 0;
 } /* }}} int plugin_unregister */
 
-/*
- * (Try to) load the shared object `file'. Won't complain if it isn't a shared
- * object, but it will bitch about a shared object not having a
- * ``module_register'' symbol..
- */
-static int plugin_load_file(const char *file, _Bool global) {
-  void (*reg_handle)(void);
-
+/* plugin_load_file loads the shared object "file" and calls its
+ * "module_register" function. Returns zero on success, non-zero otherwise. */
+static int plugin_load_file(char const *file, _Bool global) {
   int flags = RTLD_NOW;
   if (global)
     flags |= RTLD_GLOBAL;
 
   void *dlh = dlopen(file, flags);
-
   if (dlh == NULL) {
     char errbuf[1024] = "";
 
     snprintf(errbuf, sizeof(errbuf),
-             "dlopen (\"%s\") failed: %s. "
-             "The most common cause for this problem is "
-             "missing dependencies. Use ldd(1) to check "
-             "the dependencies of the plugin "
-             "/ shared object.",
+             "dlopen(\"%s\") failed: %s. "
+             "The most common cause for this problem is missing dependencies. "
+             "Use ldd(1) to check the dependencies of the plugin / shared "
+             "object.",
              file, dlerror());
 
-    ERROR("%s", errbuf);
-    /* Make sure this is printed to STDERR in any case, but also
-     * make sure it's printed only once. */
-    if (list_log != NULL)
-      fprintf(stderr, "ERROR: %s\n", errbuf);
+    /* This error is printed to STDERR unconditionally. If list_log is NULL,
+     * plugin_log() will also print to STDERR. We avoid duplicate output by
+     * checking that the list of log handlers, list_log, is not NULL. */
+    fprintf(stderr, "ERROR: %s\n", errbuf);
+    if (list_log != NULL) {
+      ERROR("%s", errbuf);
+    }
 
-    return 1;
+    return ENOENT;
   }
 
-  reg_handle = (void (*)(void))dlsym(dlh, "module_register");
+  void (*reg_handle)(void) = dlsym(dlh, "module_register");
   if (reg_handle == NULL) {
-    WARNING("Couldn't find symbol \"module_register\" in \"%s\": %s\n", file,
-            dlerror());
+    ERROR("Couldn't find symbol \"module_register\" in \"%s\": %s\n", file,
+          dlerror());
     dlclose(dlh);
-    return -1;
+    return ENOENT;
   }
 
   (*reg_handle)();
-
   return 0;
 }
 