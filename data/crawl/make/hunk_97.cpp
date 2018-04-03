       return o;
     }
 
-# ifdef __EMX__
-  /* close some handles that are unnecessary for the child process */
+  /* Close handles that are unnecessary for the child process.  */
   CLOSE_ON_EXEC(pipedes[1]);
   CLOSE_ON_EXEC(pipedes[0]);
-  /* Never use fork()/exec() here! Use spawn() instead in exec_command() */
-  pid = child_execute_job (FD_STDIN, pipedes[1], errfd, command_argv, envp);
-  if (pid < 0)
-    perror_with_name (error_prefix, "spawn");
-# else /* ! __EMX__ */
-  pid = fork ();
+
+  {
+    struct output out;
+    out.syncout = 1;
+    out.out = pipedes[1];
+    out.err = errfd;
+
+    pid = child_execute_job (&out, 1, command_argv, envp);
+  }
+
   if (pid < 0)
-    perror_with_name (error_prefix, "fork");
-  else if (pid == 0)
     {
-#  ifdef SET_STACK_SIZE
-      /* Reset limits, if necessary.  */
-      if (stack_limit.rlim_cur)
-       setrlimit (RLIMIT_STACK, &stack_limit);
-#  endif
-      child_execute_job (FD_STDIN, pipedes[1], errfd, command_argv, envp);
+      perror_with_name (error_prefix, "fork");
+      return o;
     }
-  else
-# endif
 #endif
-    {
-      /* We are the parent.  */
-      char *buffer;
-      unsigned int maxlen, i;
-      int cc;
 
-      /* Record the PID for reap_children.  */
-      shell_function_pid = pid;
+  {
+    char *buffer;
+    unsigned int maxlen, i;
+    int cc;
+
+    /* Record the PID for reap_children.  */
+    shell_function_pid = pid;
 #ifndef  __MSDOS__
-      shell_function_completed = 0;
+    shell_function_completed = 0;
 
-      /* Free the storage only the child needed.  */
-      free (command_argv[0]);
-      free (command_argv);
+    /* Free the storage only the child needed.  */
+    free (command_argv[0]);
+    free (command_argv);
 
-      /* Close the write side of the pipe.  We test for -1, since
-         pipedes[1] is -1 on MS-Windows, and some versions of MS
-         libraries barf when 'close' is called with -1.  */
-      if (pipedes[1] >= 0)
-        close (pipedes[1]);
+    /* Close the write side of the pipe.  We test for -1, since
+       pipedes[1] is -1 on MS-Windows, and some versions of MS
+       libraries barf when 'close' is called with -1.  */
+    if (pipedes[1] >= 0)
+      close (pipedes[1]);
 #endif
 
-      /* Set up and read from the pipe.  */
+    /* Set up and read from the pipe.  */
 
-      maxlen = 200;
-      buffer = xmalloc (maxlen + 1);
+    maxlen = 200;
+    buffer = xmalloc (maxlen + 1);
 
-      /* Read from the pipe until it gets EOF.  */
-      for (i = 0; ; i += cc)
-        {
-          if (i == maxlen)
-            {
-              maxlen += 512;
-              buffer = xrealloc (buffer, maxlen + 1);
-            }
+    /* Read from the pipe until it gets EOF.  */
+    for (i = 0; ; i += cc)
+      {
+        if (i == maxlen)
+          {
+            maxlen += 512;
+            buffer = xrealloc (buffer, maxlen + 1);
+          }
 
-          EINTRLOOP (cc, read (pipedes[0], &buffer[i], maxlen - i));
-          if (cc <= 0)
-            break;
-        }
-      buffer[i] = '\0';
+        EINTRLOOP (cc, read (pipedes[0], &buffer[i], maxlen - i));
+        if (cc <= 0)
+          break;
+      }
+    buffer[i] = '\0';
 
-      /* Close the read side of the pipe.  */
+    /* Close the read side of the pipe.  */
 #ifdef  __MSDOS__
-      if (fpipe)
-        {
-          int st = pclose (fpipe);
-          shell_completed (st, 0);
-        }
+    if (fpipe)
+      {
+        int st = pclose (fpipe);
+        shell_completed (st, 0);
+      }
 #else
-      (void) close (pipedes[0]);
+    (void) close (pipedes[0]);
 #endif
 
-      /* Loop until child_handler or reap_children()  sets
-         shell_function_completed to the status of our child shell.  */
-      while (shell_function_completed == 0)
-        reap_children (1, 0);
+    /* Loop until child_handler or reap_children()  sets
+       shell_function_completed to the status of our child shell.  */
+    while (shell_function_completed == 0)
+      reap_children (1, 0);
 
-      if (batch_filename)
-        {
-          DB (DB_VERBOSE, (_("Cleaning up temporary batch file %s\n"),
-                           batch_filename));
-          remove (batch_filename);
-          free (batch_filename);
-        }
-      shell_function_pid = 0;
+    if (batch_filename)
+      {
+        DB (DB_VERBOSE, (_("Cleaning up temporary batch file %s\n"),
+                         batch_filename));
+        remove (batch_filename);
+        free (batch_filename);
+      }
+    shell_function_pid = 0;
 
-      /* shell_completed() will set shell_function_completed to 1 when the
-         child dies normally, or to -1 if it dies with status 127, which is
-         most likely an exec fail.  */
+    /* shell_completed() will set shell_function_completed to 1 when the
+       child dies normally, or to -1 if it dies with status 127, which is
+       most likely an exec fail.  */
 
-      if (shell_function_completed == -1)
-        {
-          /* This likely means that the execvp failed, so we should just
-             write the error message in the pipe from the child.  */
-          fputs (buffer, stderr);
-          fflush (stderr);
-        }
-      else
-        {
-          /* The child finished normally.  Replace all newlines in its output
-             with spaces, and put that in the variable output buffer.  */
-          fold_newlines (buffer, &i, trim_newlines);
-          o = variable_buffer_output (o, buffer, i);
-        }
+    if (shell_function_completed == -1)
+      {
+        /* This likely means that the execvp failed, so we should just
+           write the error message in the pipe from the child.  */
+        fputs (buffer, stderr);
+        fflush (stderr);
+      }
+    else
+      {
+        /* The child finished normally.  Replace all newlines in its output
+           with spaces, and put that in the variable output buffer.  */
+        fold_newlines (buffer, &i, trim_newlines);
+        o = variable_buffer_output (o, buffer, i);
+      }
 
-      free (buffer);
-    }
+    free (buffer);
+  }
 
   return o;
 }
