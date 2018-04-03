       job_rfd = -1;
     }
 
+#ifdef __EMX__
+  /* The signal handler must called only once! */
+  signal (SIGCHLD, SIG_DFL);
+#endif
+
+  /* This causes problems if the SIGCHLD interrupts a printf().
   DB (DB_JOBS, (_("Got a SIGCHLD; %u unreaped children.\n"), dead_children));
+  */
 }
-#endif  /* !__EMX__ */
 
 extern int shell_function_pid, shell_function_completed;
 
