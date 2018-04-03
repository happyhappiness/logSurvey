 void
 writePidFile(void)
 {
-    FILE *pid_fp = NULL;
+    int fd;
     const char *f = NULL;
     mode_t old_umask;
-
-    if ((f = Config.pidFilename) == NULL || !strcmp(Config.pidFilename, "none"))
+    char buf[32];
+    if ((f = Config.pidFilename) == NULL)
+	return;
+    if (!strcmp(Config.pidFilename, "none"))
 	return;
     enter_suid();
     old_umask = umask(022);
-    pid_fp = fopen(f, "w");
+    fd = file_open(f, O_WRONLY | O_CREAT | O_TRUNC, NULL, NULL);
     umask(old_umask);
     leave_suid();
-    if (pid_fp != NULL) {
-	fprintf(pid_fp, "%d\n", (int) getpid());
-	fclose(pid_fp);
-    } else {
-	debug(50, 0, "WARNING: Could not write pid file\n");
-	debug(50, 0, "         %s: %s\n", f, xstrerror());
+    if (fd < 0) {
+	debug(50, 0, "%s: %s\n", f, xstrerror());
+	debug_trap("Could not write pid file");
+	return;
     }
+    sprintf(buf, "%d\n", (int) getpid());
+    write(fd, buf, strlen(buf));
+    file_close(fd);
 }
 
 
 pid_t
 readPidFile(void)
 {
     FILE *pid_fp = NULL;
-    const char *f = NULL;
+    const char *f = Config.pidFilename;
     pid_t pid = -1;
     int i;
 
-    if ((f = Config.pidFilename) == NULL || !strcmp(Config.pidFilename, "none")) {
+    if (f == NULL || !strcmp(Config.pidFilename, "none")) {
 	fprintf(stderr, "%s: ERROR: No pid file name defined\n", appname);
 	exit(1);
     }
