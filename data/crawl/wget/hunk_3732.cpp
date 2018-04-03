 print_percentage (long bytes, long expected)
 {
   int percentage = (int)(100.0 * bytes / expected);
-  logprintf (LOG_VERBOSE, " [%3d%%]", percentage);
+  logprintf (LOG_VERBOSE, "%3d%%", percentage);
 }
 
 /* Show the dotted progress report of file loading.  Called with
