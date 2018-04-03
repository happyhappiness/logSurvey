   return EXCEPTION_CONTINUE_SEARCH;
 #else
   exit(255);
+  return (255); /* not reached */
+#endif
+}
+
+/*
+ * On WIN32 systems we don't have the luxury of a /bin directory that
+ * is mapped globally to every drive mounted to the system. Since make could
+ * be invoked from any drive, and we don't want to propogate /bin/sh
+ * to every single drive. Allow ourselves a chance to search for
+ * a value for default shell here (if the default path does not exist).
+ */
+
+int
+find_and_set_default_shell(char *token)
+{
+  int sh_found = 0;
+  char* search_token;
+  PATH_VAR(sh_path);
+  extern char *default_shell;
+
+  if (!token)
+    search_token = default_shell;
+  else
+    search_token = token;
+
+  if (!no_default_sh_exe &&
+      (token == NULL || !strcmp(search_token, default_shell))) {
+    /* no new information, path already set or known */
+    sh_found = 1;
+  } else if (file_exists_p(search_token)) {
+    /* search token path was found */
+    sprintf(sh_path, "%s", search_token);
+    default_shell = strdup(w32ify(sh_path,0));
+    if (debug_flag)
+      printf("find_and_set_shell setting default_shell = %s\n", default_shell);
+    sh_found = 1;
+  } else {
+    char *p;
+    struct variable *v = lookup_variable ("Path", 4);
+
+    /*
+     * Search Path for shell
+     */
+    if (v && v->value) {
+      char *ep;
+
+      p  = v->value;
+      ep = strchr(p, PATH_SEPARATOR_CHAR);
+
+      while (ep && *ep) {
+        *ep = '\0';
+
+        if (dir_file_exists_p(p, search_token)) {
+          sprintf(sh_path, "%s/%s", p, search_token);
+          default_shell = strdup(w32ify(sh_path,0));
+          sh_found = 1;
+          *ep = PATH_SEPARATOR_CHAR;
+
+          /* terminate loop */
+          p += strlen(p);
+        } else {
+          *ep = PATH_SEPARATOR_CHAR;
+           p = ++ep;
+        }
+
+        ep = strchr(p, PATH_SEPARATOR_CHAR);
+      }
+
+      /* be sure to check last element of Path */
+      if (p && *p && dir_file_exists_p(p, search_token)) {
+          sprintf(sh_path, "%s/%s", p, search_token);
+          default_shell = strdup(w32ify(sh_path,0));
+          sh_found = 1;
+      }
+
+      if (debug_flag && sh_found)
+        printf("find_and_set_shell path search set default_shell = %s\n", default_shell);
+    }
+  }
+
+  /* naive test */
+  if (!unixy_shell && sh_found &&
+      (strstr(default_shell, "sh") || strstr(default_shell, "SH"))) {
+    unixy_shell = 1;
+    batch_mode_shell = 0;
+  }
+
+#ifdef BATCH_MODE_ONLY_SHELL
+  batch_mode_shell = 1;
 #endif
+
+  return (sh_found);
 }
 #endif  /* WINDOWS32 */
 
