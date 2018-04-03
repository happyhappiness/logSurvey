 
       if (filename && opt.delete_after && file_exists_p (filename))
 	{
+	  DEBUGP (("Removing file due to --delete-after in"
+		   " retrieve_from_file():\n"));
 	  logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
 	  if (unlink (filename))
 	    logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
