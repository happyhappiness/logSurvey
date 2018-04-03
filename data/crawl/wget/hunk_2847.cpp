       fprintf (stderr, _("\n%s received.\n"), redirect_request_signal_name);
       fprintf (stderr, _("%s: %s; disabling logging.\n"),
 	       logfile, strerror (errno));
-      inhibit_logging = 1;
+      inhibit_logging = true;
     }
-  save_context_p = 0;
+  save_context_p = false;
 }
 
 /* Check whether a signal handler requested the output to be
