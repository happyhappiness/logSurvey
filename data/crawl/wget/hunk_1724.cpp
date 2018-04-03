   if (!con->target)
     con->target = url_file_name (u);
 
-  if (opt.noclobber && file_exists_p (con->target))
+  /* If the output_document was given, then this check was already done and
+     the file doesn't exist. Hence the !opt.output_document */
+  if (opt.noclobber && !opt.output_document && file_exists_p (con->target))
     {
       logprintf (LOG_VERBOSE,
                  _("File `%s' already there; not retrieving.\n"), con->target);
