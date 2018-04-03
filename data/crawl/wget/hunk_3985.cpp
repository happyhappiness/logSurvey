     {
       logprintf (LOG_NOTQUIET,
 		 _("\nFINISHED --%s--\nDownloaded: %s bytes in %d files\n"),
-		 time_str (NULL), legible (opt.downloaded), opt.numurls);
+		 time_str (NULL), legible_very_long (opt.downloaded),
+		 opt.numurls);
       /* Print quota warning, if exceeded.  */
       if (opt.quota && opt.downloaded > opt.quota)
 	logprintf (LOG_NOTQUIET,
