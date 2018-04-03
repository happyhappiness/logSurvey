    {
      logprintf (LOG_NOTQUIET, _("Cannot convert links in %s: %s\n"),
		 file, strerror (errno));
      read_file_free (fm);
      return;
    }
  /* Here we loop through all the URLs in file, replacing those of
     them that are downloaded with relative references.  */
  p = fm->content;
  for (; l; l = l->next)
    {
      char *url_start = fm->content + l->pos;
      if (l->pos >= fm->length)
	{
	  DEBUGP (("Something strange is going on.  Please investigate."));
	  break;
	}
      /* If the URL is not to be converted, skip it.  */
      if (!(l->flags & (UABS2REL | UREL2ABS)))
	{
	  DEBUGP (("Skipping %s at position %d (flags %d).\n", l->url,
		   l->pos, l->flags));
	  continue;
	}

      /* Echo the file contents, up to the offending URL's opening
         quote, to the outfile.  */
      fwrite (p, 1, url_start - p, fp);
      p = url_start;
      if (l->flags & UABS2REL)
	{
	  /* Convert absolute URL to relative. */
	  char *newname = construct_relative (file, l->local_name);
	  putc (*p, fp);	/* quoting char */
	  fputs (newname, fp);
	  p += l->size - 1;
	  putc (*p, fp);	/* close quote */
	  ++p;
	  DEBUGP (("ABS2REL: %s to %s at position %d in %s.\n",
		   l->url, newname, l->pos, file));
	  free (newname);
	}
      else if (l->flags & UREL2ABS)
	{
	  /* Convert the link to absolute URL. */
	  char *newlink = l->url;
	  putc (*p, fp);	/* quoting char */
	  fputs (newlink, fp);
	  p += l->size - 1;
	  putc (*p, fp);	/* close quote */
	  ++p;
	  DEBUGP (("REL2ABS: <something> to %s at position %d in %s.\n",
		   newlink, l->pos, file));
	}
    }
  /* Output the rest of the file. */
  if (p - fm->content < fm->length)
    fwrite (p, 1, fm->length - (p - fm->content), fp);
  fclose (fp);
  read_file_free (fm);
  logputs (LOG_VERBOSE, _("done.\n"));
}

