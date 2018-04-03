     con->target = url_file_name (u);
 
   /* If the output_document was given, then this check was already done and
-     the file doesn't exist. Hence the !opt.output_document */
+     the file didn't exist. Hence the !opt.output_document */
   if (opt.noclobber && !opt.output_document && file_exists_p (con->target))
     {
       logprintf (LOG_VERBOSE,
