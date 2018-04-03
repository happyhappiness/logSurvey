		{
		  if (!opt.output_document)
		    {
		      struct_stat st;
		      wgint sz;
		      if (stat (filename, &st) == 0)
			sz = st.st_size;
		      else
			sz = -1;
		      logprintf (LOG_NOTQUIET,
				 _("Wrote HTML-ized index to `%s' [%s].\n"),
				 filename, number_to_static_string (sz));
		    }
		  else
		    logprintf (LOG_NOTQUIET,
