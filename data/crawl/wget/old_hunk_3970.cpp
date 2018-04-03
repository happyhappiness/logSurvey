    {
      logprintf (LOG_NOTQUIET, _("Cannot convert links in %s: %s\n"),
		 file, strerror (errno));
      free (buf);
      return;
    }
  /* Presumably we have to loop through multiple URLs here (even though we're
     only talking about a single local file) because of the -O option. */
  for (p = buf; l; l = l->next)
    {
      if (l->pos >= size)
	{
	  DEBUGP (("Something strange is going on.  Please investigate."));
	  break;
	}
      /* If the URL already is relative or it is not to be converted
	 for some other reason (e.g. because of not having been
	 downloaded in the first place), skip it.  */
      if ((l->flags & URELATIVE) || !(l->flags & UABS2REL))
	{
	  DEBUGP (("Skipping %s at position %d (flags %d).\n", l->url,
		   l->pos, l->flags));
	  continue;
	}
      /* Else, reach the position of the offending URL, echoing
	 everything up to it to the outfile.  */
      for (p2 = buf + l->pos; p < p2; p++)
	putc (*p, fp);
      if (l->flags & UABS2REL)
	/* Convert absolute URL to relative. */
	{
	  char *newname = construct_relative (file, l->local_name);
	  fprintf (fp, "%s", newname);
	  DEBUGP (("ABS2REL: %s to %s at position %d in %s.\n",
		   l->url, newname, l->pos, file));
	  free (newname);
	}
      p += l->size;
    }
  /* Output the rest of the file. */
  if (p - buf < size)
    {
      for (p2 = buf + size; p < p2; p++)
	putc (*p, fp);
    }
  fclose (fp);
  free (buf);
  logputs (LOG_VERBOSE, _("done.\n"));
}

