   if (opt.noclobber && file_exists_p (con->target))
     {
       logprintf (LOG_VERBOSE,
-                 _("File `%s' already there; not retrieving.\n"), con->target);
+                 _("File %s already there; not retrieving.\n"), quote (con->target));
       /* If the file is there, we suppose it's retrieved OK.  */
       return RETROK;
     }
