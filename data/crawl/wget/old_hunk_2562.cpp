      const char *line_beg = text;
      const char *line_end = memchr (text, '\n', text_end - text);
      if (!line_end)
	line_end = text_end;
      else
	++line_end;
      text = line_end;

      /* Strip whitespace from the beginning and end of line. */
      while (line_beg < line_end && ISSPACE (*line_beg))
	++line_beg;
      while (line_end > line_beg && ISSPACE (*(line_end - 1)))
	--line_end;

      if (line_beg == line_end)
	continue;

      /* The URL is in the [line_beg, line_end) region. */

      /* We must copy the URL to a zero-terminated string, and we
	 can't use alloca because we're in a loop.  *sigh*.  */
      url_text = strdupdelim (line_beg, line_end);

      if (opt.base_href)
	{
	  /* Merge opt.base_href with URL. */
	  char *merged = uri_merge (opt.base_href, url_text);
	  xfree (url_text);
	  url_text = merged;
	}

      url = url_parse (url_text, &up_error_code);
      if (!url)
	{
	  logprintf (LOG_NOTQUIET, _("%s: Invalid URL %s: %s\n"),
		     file, url_text, url_error (up_error_code));
	  xfree (url_text);
	  continue;
	}
      xfree (url_text);

      entry = xnew0 (struct urlpos);
      entry->url = url;

      if (!head)
	head = entry;
      else
	tail->next = entry;
      tail = entry;
    }
  read_file_free (fm);
