     int status;
 #endif
     pid_t pid;
+    int i;
     if (*(argv[0]) == '(')
 	return;
+    openlog(appname, LOG_PID | LOG_NDELAY | LOG_CONS, LOG_LOCAL4);
+    if ((pid = fork()) < 0)
+	syslog(LOG_ALERT, "fork failed: %s", xstrerror());
+    else if (pid > 0)
+	exit(0);
+    if (setsid() < 0)
+	syslog(LOG_ALERT, "setsid failed: %s", xstrerror());
+#ifdef TIOCNOTTY
+    if ((i = open("/dev/tty", O_RDWR)) >= 0) {
+	ioctl(i, TIOCNOTTY, NULL);
+	close(i);
+    }
+#endif
+    for (i = 0; i < Squid_MaxFD; i++)
+	close(i);
+    umask(0);
     for (;;) {
-	if (fork() == 0) {
+	if ((pid = fork()) == 0) {
 	    /* child */
 	    prog = xstrdup(argv[0]);
 	    argv[0] = xstrdup("(squid)");
 	    execvp(prog, argv);
-	    fatal("execvp failed");
+	    syslog(LOG_ALERT, "execvp failed: %s", xstrerror());
 	}
-	/* parent */ time(&start);
-	do {
-	    squid_signal(SIGINT, SIG_IGN, SA_RESTART);
+	/* parent */
+	syslog(LOG_NOTICE, "Squid Parent: child process %d started", pid);
+	time(&start);
+	squid_signal(SIGINT, SIG_IGN, SA_RESTART);
 #ifdef _SQUID_NEXT_
-	    pid = wait3(&status, 0, NULL);
+	pid = wait3(&status, 0, NULL);
 #else
-	    pid = waitpid(-1, &status, 0);
+	pid = waitpid(-1, &status, 0);
 #endif
-	} while (pid > 0);
 	time(&stop);
+	if (WIFEXITED(status)) {
+	    syslog(LOG_NOTICE,
+		"Squid Parent: child process %d exited with status %d",
+		pid, WEXITSTATUS(status));
+	} else if (WIFSIGNALED(status)) {
+	    syslog(LOG_NOTICE,
+		"Squid Parent: child process %d exited due to signal %d",
+		pid, WTERMSIG(status));
+	} else {
+	    syslog(LOG_NOTICE, "Squid Parent: child process %d exited", pid);
+	}
 	if (stop - start < 10)
 	    failcount++;
 	else
 	    failcount = 0;
-	if (failcount == 5)
+	if (failcount == 5) {
+	    syslog(LOG_ALERT, "Exiting due to repeated, frequent failures");
 	    exit(1);
+	}
 	if (WIFEXITED(status))
 	    if (WEXITSTATUS(status) == 0)
 		exit(0);
