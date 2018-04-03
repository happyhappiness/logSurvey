 #endif
 #else /* HAVE_SETRLIMIT */
     debug(21, 1, "setMaxFD: Cannot increase: setrlimit() not supported on this system");
-#endif
+#endif /* HAVE_SETRLIMIT */
+
+#if HAVE_SETRLIMIT && defined(RLIMIT_DATA)
+    if (getrlimit(RLIMIT_DATA, &rl) < 0) {
+	debug(21, 0, "getrlimit: RLIMIT_DATA: %s", xstrerror());
+    } else {
+	rl.rlim_cur = rl.rlim_max;	/* set it to the max */
+	if (setrlimit(RLIMIT_DATA, &rl) < 0) {
+	    sprintf(tmp_error_buf, "setrlimit: RLIMIT_DATA: %s", xstrerror());
+	    fatal_dump(tmp_error_buf);
+	}
+    }
+#endif /* RLIMIT_DATA */
 }
 
 time_t getCurrentTime()
 {
+#if defined(_SQUID_MOTOROLA_)
+    gettimeofday(&current_time);
+#else
     gettimeofday(&current_time, NULL);
-    return squid_curtime = current_time.tv_sec;
-}
-
-
-void reconfigure(sig)
-     int sig;
-{
-    int i;
-    int lft = getShutdownLifetime();
-    FD_ENTRY *f;
-    debug(21, 1, "reconfigure: SIGHUP received.\n");
-    serverConnectionsClose();
-    ipcacheShutdownServers();
-    ftpServerClose();
-    reread_pending = 1;
-    for (i = fdstat_biggest_fd(); i >= 0; i--) {
-	f = &fd_table[i];
-	if (f->read_handler || f->write_handler || f->except_handler)
-	    if (fdstatGetType(i) == Socket)
-		comm_set_fd_lifetime(i, lft);
-    }
-#if RESET_SIGNAL_HANDLER
-    signal(sig, reconfigure);
 #endif
+    return squid_curtime = current_time.tv_sec;
 }
 
 int tvSubMsec(t1, t2)
