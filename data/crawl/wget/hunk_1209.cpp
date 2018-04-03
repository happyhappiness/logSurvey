   /* TODO: perform this check only once. */
   if (!hs->existence_checked && file_exists_p (hs->local_file))
     {
-      if (opt.noclobber)
+      if (opt.noclobber && !opt.output_document)
         {
           /* If opt.noclobber is turned on and file already exists, do not
-             retrieve the file */
+             retrieve the file. But if the output_document was given, then this
+             test was already done and the file doesn't exist. Hence the !opt.output_document */
           logprintf (LOG_VERBOSE, _("\
 File `%s' already there; not retrieving.\n\n"), hs->local_file);
           /* If the file is there, we suppose it's retrieved OK.  */
