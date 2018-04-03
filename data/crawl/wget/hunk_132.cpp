   convert_links_in_hashtable (downloaded_css_set, 1, &file_count);
 
   secs = ptimer_measure (timer);
-  logprintf (LOG_VERBOSE, _("Converted %d files in %s seconds.\n"),
+  logprintf (LOG_VERBOSE, _("Converted links in %d files in %s seconds.\n"),
              file_count, print_decimal (secs));
 
   ptimer_destroy (timer);
