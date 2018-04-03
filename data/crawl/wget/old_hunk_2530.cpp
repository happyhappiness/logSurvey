    {
      fprintf (fp, "  ");
      if (f->tstamp != -1)
	{
	  /* #### Should we translate the months?  Or, even better, use
	     ISO 8601 dates?  */
	  static const char *months[] = {
	    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
	    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	  };
	  struct tm *ptm = localtime ((time_t *)&f->tstamp);

	  fprintf (fp, "%d %s %02d ", ptm->tm_year + 1900, months[ptm->tm_mon],
		  ptm->tm_mday);
	  if (ptm->tm_hour)
	    fprintf (fp, "%02d:%02d  ", ptm->tm_hour, ptm->tm_min);
	  else
	    fprintf (fp, "       ");
	}
      else
	fprintf (fp, _("time unknown       "));
      switch (f->type)
	{
	case FT_PLAINFILE:
	  fprintf (fp, _("File        "));
	  break;
	case FT_DIRECTORY:
	  fprintf (fp, _("Directory   "));
	  break;
	case FT_SYMLINK:
	  fprintf (fp, _("Link        "));
	  break;
	default:
	  fprintf (fp, _("Not sure    "));
	  break;
	}
      htclfile = html_quote_string (f->name);
      fprintf (fp, "<a href=\"ftp://%s%s:%d", upwd, u->host, u->port);
      if (*u->dir != '/')
	putc ('/', fp);
      fprintf (fp, "%s", u->dir);
      if (*u->dir)
	putc ('/', fp);
      fprintf (fp, "%s", htclfile);
      if (f->type == FT_DIRECTORY)
	putc ('/', fp);
      fprintf (fp, "\">%s", htclfile);
      if (f->type == FT_DIRECTORY)
	putc ('/', fp);
      fprintf (fp, "</a> ");
      if (f->type == FT_PLAINFILE)
	fprintf (fp, _(" (%s bytes)"), number_to_static_string (f->size));
      else if (f->type == FT_SYMLINK)
	fprintf (fp, "-> %s", f->linkto ? f->linkto : "(nil)");
      putc ('\n', fp);
      xfree (htclfile);
      f = f->next;
