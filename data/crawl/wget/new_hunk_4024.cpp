      for (p2 = buf + l->pos; p < p2; p++)
	putc (*p, fp);
      if (l->flags & UABS2REL)
	/* Convert absolute URL to relative. */
	{
	  char *newname = construct_relative (file, l->local_name);
	  fprintf (fp, "%s", newname);
