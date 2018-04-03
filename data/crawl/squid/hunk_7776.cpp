 	fprintf(debug_log, "FATAL: Received bus error...dying.\n");
     else
 	fprintf(debug_log, "FATAL: Received signal %d...dying.\n", sig);
+#if !HAVE_SIGACTION
     signal(SIGSEGV, SIG_DFL);
     signal(SIGBUS, SIG_DFL);
     signal(sig, SIG_DFL);
+#endif
     storeWriteCleanLog();
     PrintRusage(NULL, debug_log);
     print_warranty();
     abort();
 }
 
 
-void rotate_logs(sig)
+void sigusr2_handle(sig)
      int sig;
 {
-    debug(21, 1, "rotate_logs: SIGUSR1 received.\n");
-
-    storeWriteCleanLog();
-    storeRotateLog();
-    neighbors_rotate_log();
-    stat_rotate_log();
-    _db_rotate_log();
-#if RESET_SIGNAL_HANDLER
-    signal(sig, rotate_logs);
+    static int state = 0;
+    debug(21, 1, "sigusr2_handle: SIGUSR2 received.\n");
+    if (state == 0) {
+	_db_init(getCacheLogFile(), "ALL,10");
+	state = 1;
+    } else {
+	_db_init(getCacheLogFile(), getDebugOptions());
+	state = 0;
+    }
+#if !HAVE_SIGACTION
+    signal(sig, sigusr2_handle);	/* reinstall */
 #endif
 }
 
+void setSocketShutdownLifetimes()
+{
+    FD_ENTRY *f = NULL;
+    int lft = getShutdownLifetime();
+    int cur;
+    int i;
+    for (i = fdstat_biggest_fd(); i >= 0; i--) {
+	f = &fd_table[i];
+	if (!f->read_handler && !f->write_handler && !f->except_handler)
+	    continue;
+	if (fdstatGetType(i) != FD_SOCKET)
+	    continue;
+	cur = comm_get_fd_lifetime(i);
+	if (cur > 0 && (cur - squid_curtime) <= lft)
+	    continue;
+	comm_set_fd_lifetime(i, lft);
+    }
+}
+
 void normal_shutdown()
 {
     debug(21, 1, "Shutting down...\n");
     if (getPidFilename()) {
-	get_suid();
+	enter_suid();
 	safeunlink(getPidFilename(), 0);
-	check_suid();
+	leave_suid();
     }
     storeWriteCleanLog();
     PrintRusage(NULL, debug_log);
     debug(21, 0, "Squid Cache (Version %s): Exiting normally.\n",
 	version_string);
     exit(0);
 }
-void shut_down(sig)
-     int sig;
-{
-    int i;
-    int lft = getShutdownLifetime();
-    FD_ENTRY *f;
-    debug(21, 1, "Preparing for shutdown after %d connections\n",
-	ntcpconn + nudpconn);
-    serverConnectionsClose();
-    ipcacheShutdownServers();
-    ftpServerClose();
-    for (i = fdstat_biggest_fd(); i >= 0; i--) {
-	f = &fd_table[i];
-	if (f->read_handler || f->write_handler || f->except_handler)
-	    if (fdstatGetType(i) == Socket)
-		comm_set_fd_lifetime(i, lft);
-    }
-    shutdown_pending = 1;
-    /* reinstall signal handler? */
-}
 
 void fatal_common(message)
      char *message;
