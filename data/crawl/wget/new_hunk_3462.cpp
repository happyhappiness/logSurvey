
      if (!link_has_scheme)
	{
	  /* Base URL is unavailable, and the link does not have a
	     location attached to it -- we have to give up.  Since
	     this can only happen when using `--force-html -i', print
	     a warning.  */
	  logprintf (LOG_NOTQUIET,
		     _("%s: Cannot resolve relative link %s.\n"),
		     ctx->document_file, link_uri);
	  return NULL;
	}

