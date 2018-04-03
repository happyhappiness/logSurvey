 
   define_makeflags (0, 0);
 
+#ifdef WIN32
+  /*
+   * Now that makefiles are parsed, see if a Makefile gave a
+   * value for SHELL and use that for default_shell instead if
+   * that filename exists. This should speed up the
+   * construct_argv_internal() function by avoiding unnecessary
+   * recursion.
+   */
+  {
+    struct variable *v = lookup_variable("SHELL", 5);
+    extern char* default_shell;
+
+    /*
+     * to change value:
+     *
+     * SHELL must be found, SHELL must be set, value of SHELL
+     * must be different from current value, and the
+     * specified file must exist. Whew!
+     */
+    if (v != 0 && *v->value != '\0') {
+      char *fn = recursively_expand(v);
+
+      if (fn && strcmp(fn, default_shell) && file_exists_p(fn)) {
+        char *p;
+
+        default_shell = fn;
+
+        /* if Makefile says SHELL is sh.exe, believe it */
+        if (strstr(default_shell, "sh.exe"))
+               no_default_sh_exe = 0;
+
+        /*
+         * Convert from backslashes to forward slashes so
+         * create_command_line_argv_internal() is not confused.
+         */
+        for (p = strchr(default_shell, '\\'); p; p = strchr(default_shell, '\\'))
+          *p = '/';
+      }
+    }
+  }
+  if (no_default_sh_exe && job_slots != 1) {
+    error("Do not specify -j or --jobs if sh.exe is not available.");
+    error("Resetting make for single job mode.");
+    job_slots = 1;
+  }
+#endif /* WIN32 */
+
   /* Define the default variables.  */
   define_default_variables ();
 
