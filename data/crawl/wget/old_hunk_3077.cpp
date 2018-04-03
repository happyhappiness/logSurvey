		{
		  if (!opt.output_document)
		    {
		      struct stat st;
		      long sz;
		      if (stat (filename, &st) == 0)
			sz = st.st_size;
		      else
			sz = -1;
		      logprintf (LOG_NOTQUIET,
				 _("Wrote HTML-ized index to `%s' [%ld].\n"),
				 filename, sz);
		    }
		  else
		    logprintf (LOG_NOTQUIET,
