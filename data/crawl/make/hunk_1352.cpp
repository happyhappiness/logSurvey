       return 0;
     *ap = '\0';
 
+#ifdef WINDOWS32
+    /*
+	 * Some shells do not work well when invoked as 'sh -c  xxx' to run
+	 * a command line (e.g. Cygnus GNUWIN32 sh.exe on WIN32 systems).
+	 * In these cases, run commands via a script file.
+     */
+    if ((no_default_sh_exe || batch_mode_shell) && batch_filename_ptr) {
+      FILE* batch = NULL;
+      int id = GetCurrentProcessId();
+      PATH_VAR(fbuf);
+      char* fname = NULL;
+
+      /* create a file name */
+      sprintf(fbuf, "make%d", id);
+      fname = tempnam(".", fbuf);
+
+	  /* create batch file name */
+      *batch_filename_ptr = xmalloc(strlen(fname) + 5);
+      strcpy(*batch_filename_ptr, fname);
+
+      /* make sure path name is in DOS backslash format */
+      if (!unixy_shell) {
+        fname = *batch_filename_ptr;
+        for (i = 0; fname[i] != '\0'; ++i)
+          if (fname[i] == '/')
+            fname[i] = '\\';
+        strcat(*batch_filename_ptr, ".bat");
+      } else {
+        strcat(*batch_filename_ptr, ".sh");
+      }
+
+      if (debug_flag)
+        printf("Creating temporary batch file %s\n", *batch_filename_ptr);
+
+      /* create batch file to execute command */
+      batch = fopen (*batch_filename_ptr, "w");
+      fputs ("@echo off\n", batch);
+      fputs (command_ptr, batch);
+      fputc ('\n', batch);
+      fclose (batch);
+
+      /* create argv */
+      new_argv = (char **) xmalloc(3 * sizeof(char *));
+      if (unixy_shell) {
+        new_argv[0] = strdup (shell);
+        new_argv[1] = *batch_filename_ptr; /* only argv[0] gets freed later */
+      } else {
+        new_argv[0] = strdup (*batch_filename_ptr);
+        new_argv[1] = NULL;
+      }
+      new_argv[2] = NULL;
+    } else
+#endif /* WINDOWS32 */
     if (unixy_shell)
       new_argv = construct_command_argv_internal (new_line, (char **) NULL,
-                                                  (char *) 0, (char *) 0);
+                                                  (char *) 0, (char *) 0,
+                                                  (char *) 0);
 #ifdef  __MSDOS__
     else
       {
