   wgint row_bytes = opt.dot_bytes * opt.dots_in_line;
   int i;
 
-  log_set_flush (0);
+  log_set_flush (false);
 
   if (dp->dots == 0)
     logprintf (LOG_VERBOSE, "\n%5ldK", (long) (dp->rows * row_bytes / 1024));
