       /* If opt.noclobber is turned on and file already exists, do not
 	 retrieve the file */
       logprintf (LOG_VERBOSE, _("\
-File `%s' already there, will not retrieve.\n"), *hstat.local_file);
+File `%s' already there; not retrieving.\n\n"), *hstat.local_file);
       /* If the file is there, we suppose it's retrieved OK.  */
       *dt |= RETROKF;
 
