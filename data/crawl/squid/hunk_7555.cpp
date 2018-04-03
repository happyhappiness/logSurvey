     return 0;
 }
 
-void death(sig)
-     int sig;
+void
+death(int sig)
 {
     if (sig == SIGSEGV)
 	fprintf(debug_log, "FATAL: Received Segment Violation...dying.\n");
