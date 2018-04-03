   } else if (file_exists_p(search_token)) {
     /* search token path was found */
     sprintf(sh_path, "%s", search_token);
-    default_shell = strdup(w32ify(sh_path,0));
+    default_shell = xstrdup(w32ify(sh_path,0));
     if (debug_flag)
       printf("find_and_set_shell setting default_shell = %s\n", default_shell);
     sh_found = 1;
