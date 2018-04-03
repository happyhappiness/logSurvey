		 tms, tmrate, locf, len);
      logprintf (LOG_NONVERBOSE, "%s URL: %s [%ld] -> \"%s\" [%d]\n",
		 tms, u->url, len, locf, count);

      if ((con->cmd & DO_LIST))
	/* This is a directory listing file. */
	{
	  if (!opt.remove_listing)
	    /* --dont-remove-listing was specified, so do count this towards the
	       number of bytes and files downloaded. */
	    {
	      opt.downloaded += len;
	      opt.numurls++;
	    }

	  /* Deletion of listing files is not controlled by --delete-after, but
	     by the more specific option --dont-remove-listing, and the code
	     to do this deletion is in another function. */
	}
      else
	/* This is not a directory listing file. */
	{
	  /* Unlike directory listing files, don't pretend normal files weren't
	     downloaded if they're going to be deleted.  People seeding proxies,
	     for instance, may want to know how many bytes and files they've
	     downloaded through it. */
	  opt.downloaded += len;
	  opt.numurls++;

	  if (opt.delete_after)
	    {
	      DEBUGP (("Removing file due to --delete-after in"
		       " ftp_loop_internal():\n"));
	      logprintf (LOG_VERBOSE, _("Removing %s.\n"), locf);
	      if (unlink (locf))
		logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
	    }
	}
      
      /* Restore the original leave-pendingness.  */
      if (orig_lp)
	con->cmd |= LEAVE_PENDING;
