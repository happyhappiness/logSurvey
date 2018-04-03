 
 #ifdef VMS
   if (!(exit_code & 1))
-      error("*** [%s] Error 0x%x%s", target_name, exit_code, ((ignored)? " (ignored)" : ""));
+      error (NILF, "*** [%s] Error 0x%x%s", target_name, exit_code, ((ignored)? " (ignored)" : ""));
 #else
   if (exit_sig == 0)
-    error (ignored ? "[%s] Error %d (ignored)" :
+    error (NILF, ignored ? "[%s] Error %d (ignored)" :
 	   "*** [%s] Error %d",
 	   target_name, exit_code);
   else
-    error ("*** [%s] %s%s",
+    error (NILF, "*** [%s] %s%s",
 	   target_name, strsignal (exit_sig),
 	   coredump ? " (core dumped)" : "");
 #endif /* VMS */
 }
 
-static unsigned int dead_children = 0;
-
 #ifdef VMS
 /* Wait for nchildren children to terminate */
 static void
