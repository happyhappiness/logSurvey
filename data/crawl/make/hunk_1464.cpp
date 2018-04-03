   if (ignored && silent_flag)
     return;
 
+#ifdef VMS
+  if (!(exit_code & 1))
+      error("*** [%s] Error 0x%x%s", target_name, exit_code, ((ignored)? " (ignored)" : ""));
+#else
   if (exit_sig == 0)
     error (ignored ? "[%s] Error %d (ignored)" :
 	   "*** [%s] Error %d",
