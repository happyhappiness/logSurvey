 
 void setMaxFD()
 {
-#if defined(HAVE_SETRLIMIT)
+#if HAVE_SETRLIMIT
     /* try to use as many file descriptors as possible */
     /* System V uses RLIMIT_NOFILE and BSD uses RLIMIT_OFILE */
     struct rlimit rl;
 #if defined(RLIMIT_NOFILE)
     if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
-	perror("getrlimit: RLIMIT_NOFILE");
+	debug(21, 0, "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
     } else {
-	rl.rlim_cur = rl.rlim_max;	/* set it to the max */
+	rl.rlim_cur = FD_SETSIZE;
 	if (setrlimit(RLIMIT_NOFILE, &rl) < 0) {
-	    perror("setrlimit: RLIMIT_NOFILE");
+	    sprintf(tmp_error_buf, "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
+	    fatal_dump(tmp_error_buf);
 	}
     }
 #elif defined(RLIMIT_OFILE)
     if (getrlimit(RLIMIT_OFILE, &rl) < 0) {
-	perror("getrlimit: RLIMIT_OFILE");
+	debug(21, 0, "setrlimit: RLIMIT_NOFILE: %s", xstrerror());
     } else {
-	rl.rlim_cur = rl.rlim_max;	/* set it to the max */
+	rl.rlim_cur = FD_SETSIZE;
 	if (setrlimit(RLIMIT_OFILE, &rl) < 0) {
-	    perror("setrlimit: RLIMIT_OFILE");
+	    sprintf(tmp_error_buf, "setrlimit: RLIMIT_OFILE: %s", xstrerror());
+	    fatal_dump(tmp_error_buf);
 	}
     }
 #endif
-    debug(21, 1, "setMaxFD: Using %d file descriptors\n", rl.rlim_max);
 #else /* HAVE_SETRLIMIT */
     debug(21, 1, "setMaxFD: Cannot increase: setrlimit() not supported on this system");
 #endif
