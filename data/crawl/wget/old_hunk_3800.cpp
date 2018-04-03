	  /* Convert absolute URL to relative. */
	  char *newname = construct_relative (file, l->local_name);
	  char *quoted_newname = html_quote_string (newname);
	  putc (*p, fp);	/* quoting char */
	  fputs (quoted_newname, fp);
	  p += l->size - 1;
	  putc (*p, fp);	/* close quote */
	  ++p;
	  xfree (newname);
	  xfree (quoted_newname);
	  DEBUGP (("TO_RELATIVE: %s to %s at position %d in %s.\n",
		   l->url, newname, l->pos, file));
	}
      else if (l->convert == CO_CONVERT_TO_COMPLETE)
	{
	  /* Convert the link to absolute URL. */
	  char *newlink = l->url;
	  char *quoted_newlink = html_quote_string (newlink);
	  putc (*p, fp);	/* quoting char */
	  fputs (quoted_newlink, fp);
	  p += l->size - 1;
	  putc (*p, fp);	/* close quote */
	  ++p;
	  xfree (quoted_newlink);
	  DEBUGP (("TO_COMPLETE: <something> to %s at position %d in %s.\n",
		   newlink, l->pos, file));
	}
    }
  /* Output the rest of the file. */
