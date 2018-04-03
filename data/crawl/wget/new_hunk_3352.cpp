  return ctx.head;
}

/* This doesn't really have anything to do with HTML, but it's similar
   to get_urls_html, so we put it here.  */

struct urlpos *
get_urls_file (const char *file)
{
  struct file_memory *fm;
  struct urlpos *head, *tail;
  const char *text, *text_end;

  /* Load the file.  */
  fm = read_file (file);
  if (!fm)
    {
      logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
      return NULL;
    }
  DEBUGP (("Loaded %s (size %ld).\n", file, fm->length));

  head = tail = NULL;
  text = fm->content;
  text_end = fm->content + fm->length;
  while (text < text_end)
    {
      int up_error_code;
      char *url_text;
      struct urlpos *entry;
      struct url *url;

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
	  logprintf (LOG_NOTQUIET, "%s: Invalid URL %s: %s\n",
		     file, url_text, url_error (up_error_code));
	  xfree (url_text);
	  continue;
	}
      xfree (url_text);

      entry = (struct urlpos *)xmalloc (sizeof (struct urlpos));
      memset (entry, 0, sizeof (*entry));
      entry->next = NULL;
      entry->url = url;

      if (!head)
	head = entry;
      else
	tail->next = entry;
      tail = entry;
    }
  read_file_free (fm);
  return head;
}

void
cleanup_html_url (void)
{
