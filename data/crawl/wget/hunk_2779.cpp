       free_urlpos (urls);
     }
 
-  secs = ptimer_measure (timer) / 1000;
+  secs = ptimer_measure (timer);
   ptimer_destroy (timer);
   logprintf (LOG_VERBOSE, _("Converted %d files in %s seconds.\n"),
 	     file_count, print_decimal (secs));
