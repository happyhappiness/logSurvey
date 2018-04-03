     }
 
   wtimer_update (timer);
-  msecs = wtimer_read (timer);
+  secs = wtimer_read (timer) / 1000;
   wtimer_delete (timer);
-  logprintf (LOG_VERBOSE, _("Converted %d files in %.2f seconds.\n"),
-	     file_count, (double)msecs / 1000);
+  logprintf (LOG_VERBOSE, _("Converted %d files in %.*f seconds.\n"),
+	     file_count, secs < 10 ? 3 : 1, secs);
 }
 
 static void write_backup_file PARAMS ((const char *, downloaded_file_t));
