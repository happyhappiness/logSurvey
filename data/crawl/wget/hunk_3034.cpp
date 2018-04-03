     {
       logprintf (LOG_NOTQUIET,
 		 _("\nFINISHED --%s--\nDownloaded: %s bytes in %d files\n"),
-		 time_str (NULL), legible_large_int (total_downloaded_bytes),
+		 time_str (NULL), with_thousand_seps_large (total_downloaded_bytes),
 		 opt.numurls);
       /* Print quota warning, if exceeded.  */
       if (opt.quota && total_downloaded_bytes > opt.quota)
 	logprintf (LOG_NOTQUIET,
 		   _("Download quota (%s bytes) EXCEEDED!\n"),
-		   legible (opt.quota));
+		   with_thousand_seps_large (opt.quota));
     }
 
   if (opt.cookies_output)
