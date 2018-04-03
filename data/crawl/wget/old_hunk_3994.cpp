	  else
	    DEBUGP (("%s is not text/html so we don't chase.\n",
		     filename ? filename: "(null)"));
	  /* If an suffix-rejected file was loaded only because it was HTML,
	     undo the error now */
	  if (opt.delete_after || (filename && !acceptable (filename)))
	    {
	      logprintf (LOG_VERBOSE,
			 (opt.delete_after ? _("Removing %s.\n")
			  : _("Removing %s since it should be rejected.\n")),
