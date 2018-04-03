   }
 
   logputs (LOG_VERBOSE, "\n\n");
-  log_set_flush (0);
+  log_set_flush (false);
 
   xfree (dp);
 }
