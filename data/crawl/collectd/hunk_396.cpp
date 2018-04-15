   }
 
   pl->pid = 0;
+
+  pthread_mutex_lock (&pl_lock);
+  pl->flags &= ~PL_RUNNING;
+  pthread_mutex_unlock (&pl_lock);
+
   pthread_exit ((void *) 0);
   return (NULL);
 } /* void *exec_read_one }}} */
 
+static void *exec_notification_one (void *arg) /* {{{ */
+{
+  program_list_t *pl = ((program_list_and_notification_t *) arg)->pl;
+  const notification_t *n = ((program_list_and_notification_t *) arg)->n;
+  int fd;
+  FILE *fh;
+  int pid;
+  int status;
+  const char *severity;
+
+  pid = fork_child (pl, &fd, NULL);
+  if (pid < 0)
+    pthread_exit ((void *) 1);
+
+  fh = fdopen (fd, "w");
+  if (fh == NULL)
+  {
+    char errbuf[1024];
+    ERROR ("exec plugin: fdopen (%i) failed: %s", fd,
+	sstrerror (errno, errbuf, sizeof (errbuf)));
+    kill (pl->pid, SIGTERM);
+    pl->pid = 0;
+    close (fd);
+    pthread_exit ((void *) 1);
+  }
+
+  severity = "FAILURE";
+  if (n->severity == NOTIF_WARNING)
+    severity = "WARNING";
+  else if (n->severity == NOTIF_OKAY)
+    severity = "OKAY";
+
+  fprintf (fh, "Severity: %s\n"
+      "Time: %u\n"
+      "Host: %s\n"
+      "Message: %s\n"
+      "\n",
+      severity, (unsigned int) n->time, n->host, n->message);
+  fflush (fh);
+  fclose (fh);
+
+  waitpid (pid, &status, 0);
+
+  DEBUG ("exec plugin: Child %i exited with status %i.",
+      pid, status);
+
+  pthread_exit ((void *) 0);
+  return (NULL);
+} /* void *exec_notification_one }}} */
+
 static int exec_init (void) /* {{{ */
 {
   struct sigaction sa;
