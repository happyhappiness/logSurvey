   secs = ptimer_measure (timer);
   logprintf (LOG_VERBOSE, _("Converted %d files in %s seconds.\n"),
              file_count, print_decimal (secs));
-cleanup:
+
   ptimer_destroy (timer);
 }
 
