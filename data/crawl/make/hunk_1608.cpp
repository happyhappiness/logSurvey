      int exit_code, exit_sig, coredump;
      int ignored;
 {
-  char *ignore_string = ignored ? " (ignored)" : "";
-
   if (exit_sig == 0)
-    error ("*** [%s] Error %d%s", target_name, exit_code, ignore_string);
+    error (ignored ? "[%s] Error %d (ignored)" :
+	   "*** [%s] Error %d%s",
+	   target_name, exit_code);
   else
     {
       char *coredump_string = coredump ? " (core dumped)" : "";
