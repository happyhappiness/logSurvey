       || (opt.input_filename && total_downloaded_bytes != 0))
     {
       logprintf (LOG_NOTQUIET,
-		 _("\nFINISHED --%s--\nDownloaded: %s bytes in %d files\n"),
+		 _("\nFINISHED --%s--\nDownloaded: %s in %d files\n"),
 		 time_str (NULL),
-		 with_thousand_seps_sum (total_downloaded_bytes),
+		 human_readable (total_downloaded_bytes),
 		 opt.numurls);
       /* Print quota warning, if exceeded.  */
       if (opt.quota && total_downloaded_bytes > opt.quota)
 	logprintf (LOG_NOTQUIET,
-		   _("Download quota (%s bytes) EXCEEDED!\n"),
-		   with_thousand_seps_sum (opt.quota));
+		   _("Download quota of %s EXCEEDED!\n"),
+		   human_readable (opt.quota));
     }
 
   if (opt.cookies_output)
