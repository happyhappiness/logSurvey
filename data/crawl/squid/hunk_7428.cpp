     if ((pid = fork()) < 0) {
 	debug(50, 0, "ftpInitialize: fork: %s\n", xstrerror());
 	comm_close(cfd);
-	return -1;
+	fatal("Failed to fork() for ftpget.");
     }
     if (pid != 0) {		/* parent */
 	comm_close(cfd);