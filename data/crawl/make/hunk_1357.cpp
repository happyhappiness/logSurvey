 
   define_makeflags (0, 0);
 
-#ifdef WINDOWS32
-  /*
-   * Now that makefiles are parsed, see if a Makefile gave a
-   * value for SHELL and use that for default_shell instead if
-   * that filename exists. This should speed up the
-   * construct_argv_internal() function by avoiding unnecessary
-   * recursion.
-   */
-  {
-    struct variable *v = lookup_variable("SHELL", 5);
-    extern char* default_shell;
+  /* Define the default variables.  */
+  define_default_variables ();
 
-    /*
-     * to change value:
-     *
-     * SHELL must be found, SHELL must be set, value of SHELL
-     * must be different from current value, and the
-     * specified file must exist. Whew!
-     */
-    if (v != 0 && *v->value != '\0') {
-      char *fn = recursively_expand(v);
+  /* Read all the makefiles.  */
 
-      if (fn && strcmp(fn, default_shell) && file_exists_p(fn)) {
-        char *p;
+  default_file = enter_file (".DEFAULT");
 
-        default_shell = fn;
+  read_makefiles
+    = read_all_makefiles (makefiles == 0 ? (char **) 0 : makefiles->list);
 
-        /* if Makefile says SHELL is sh.exe, believe it */
-        if (strstr(default_shell, "sh.exe"))
-               no_default_sh_exe = 0;
+#ifdef WINDOWS32
+  /* look one last time after reading all Makefiles */
+  if (no_default_sh_exe)
+    no_default_sh_exe = !find_and_set_default_shell(NULL);
 
-        /*
-         * Convert from backslashes to forward slashes so
-         * create_command_line_argv_internal() is not confused.
-         */
-        for (p = strchr(default_shell, '\\'); p; p = strchr(default_shell, '\\'))
-          *p = '/';
-      }
-    }
-  }
   if (no_default_sh_exe && job_slots != 1) {
     error("Do not specify -j or --jobs if sh.exe is not available.");
     error("Resetting make for single job mode.");
