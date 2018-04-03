 	puts(dead_msg());
 }
 
-void death()
+void death(sig)
+	int sig;
 {
-    fprintf(stderr, "FATAL: Received Segment Violation...dying.\n");
+    if (sig == SIGSEGV)
+    	fprintf(stderr, "FATAL: Received Segment Violation...dying.\n");
+    else if (sig == SIGBUS)
+        fprintf(stderr, "FATAL: Received bus error...dying.\n");
+    else
+        fprintf(stderr, "FATAL: Received signal %d...dying.\n", sig);
     signal(SIGSEGV, SIG_DFL);
     signal(SIGBUS, SIG_DFL);
+    signal(sig, SIG_DFL);
     storeWriteCleanLog();
     PrintRusage(NULL, stderr);
     print_warranty();
     abort();
 }
 
 
-void deathb()
-{
-    fprintf(stderr, "FATAL: Received bus error...dying.\n");
-    signal(SIGSEGV, SIG_DFL);
-    signal(SIGBUS, SIG_DFL);
-    signal(SIGBUS, SIG_DFL);
-    storeWriteCleanLog();
-    PrintRusage(NULL, stderr);
-    print_warranty();
-    abort();
-}
-
 void rotate_logs(sig)
      int sig;
 {