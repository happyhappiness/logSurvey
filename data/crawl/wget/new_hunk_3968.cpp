  return res;
}

urlpos *
get_urls_file (const char *file)
{
  struct file_memory *fm;
  urlpos *head, *tail;
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
      const char *line_beg = text;
      const char *line_end = memchr (text, '\n', text_end - text);
      if (!line_end)
	line_end = text_end;
      else
	++line_end;
      text = line_end;
      while (line_beg < line_end
	     && ISSPACE (*line_beg))
	++line_beg;
      while (line_end > line_beg + 1
	     && ISSPACE (*(line_end - 1)))
	--line_end;
      if (line_end > line_beg)
	{
	  urlpos *entry = (urlpos *)xmalloc (sizeof (urlpos));
	  memset (entry, 0, sizeof (*entry));
	  entry->next = NULL;
	  entry->url = strdupdelim (line_beg, line_end);
	  if (!head)
	    head = entry;
	  else
	    tail->next = entry;
	  tail = entry;
	}
    }
  read_file_free (fm);
  return head;
}

/* Free the linked list of urlpos.  */
