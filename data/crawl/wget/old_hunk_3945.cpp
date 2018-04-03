	{
	  /* Convert absolute URL to relative. */
	  char *newname = construct_relative (file, l->local_name);
	  putc (*p, fp);	/* quoting char */
	  fputs (newname, fp);
	  p += l->size - 1;
	  putc (*p, fp);	/* close quote */
	  ++p;
	  DEBUGP (("TO_RELATIVE: %s to %s at position %d in %s.\n",
		   l->url, newname, l->pos, file));
	  free (newname);
	}
      else if (l->convert == CO_CONVERT_TO_COMPLETE)
	{
	  /* Convert the link to absolute URL. */
	  char *newlink = l->url;
	  putc (*p, fp);	/* quoting char */
	  fputs (newlink, fp);
	  p += l->size - 1;
	  putc (*p, fp);	/* close quote */
	  ++p;
	  DEBUGP (("TO_COMPLETE: <something> to %s at position %d in %s.\n",
		   newlink, l->pos, file));
	}
