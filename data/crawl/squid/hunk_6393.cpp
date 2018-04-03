 	if (rl.rlim_cur > rl.rlim_max)
 	    Squid_MaxFD = rl.rlim_cur = rl.rlim_max;
 	if (setrlimit(RLIMIT_OFILE, &rl) < 0) {
-	    snprintf(tmp_error_buf, ERROR_BUF_SZ,
+	    xsnprintf(tmp_error_buf, ERROR_BUF_SZ,
 		"setrlimit: RLIMIT_OFILE: %s", xstrerror());
 	    fatal_dump(tmp_error_buf);
 	}