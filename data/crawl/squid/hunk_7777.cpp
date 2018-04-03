 
     if ((f = getPidFilename()) == NULL)
 	return;
-    if ((pid_fp = fopen(f, "w")) == NULL) {
+    enter_suid();
+    pid_fp = fopen(f, "w");
+    leave_suid();
+    if (pid_fp != NULL) {
+	fprintf(pid_fp, "%d\n", (int) getpid());
+	fclose(pid_fp);
+    } else {
 	debug(21, 0, "WARNING: Could not write pid file\n");
 	debug(21, 0, "         %s: %s\n", f, xstrerror());
-	return;
     }
-    fprintf(pid_fp, "%d\n", (int) getpid());
-    fclose(pid_fp);
 }
 
 
