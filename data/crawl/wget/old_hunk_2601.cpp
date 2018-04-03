
      /* Check for max. number of redirections.  */
      if (++redirection_count > opt.max_redirect)
	{
	  logprintf (LOG_NOTQUIET, _("%d redirections exceeded.\n"),
		     opt.max_redirect);
	  url_free (newloc_parsed);
	  url_free (u);
	  xfree (url);
	  xfree (mynewloc);
	  RESTORE_POST_DATA;
	  return WRONGCODE;
	}

      xfree (url);
      url = mynewloc;
