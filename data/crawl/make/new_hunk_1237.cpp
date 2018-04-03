      0
    };

  static char *libpatterns = NULL;

  char *libname = &(*lib)[2];	/* Name without the `-l'.  */
  FILE_TIMESTAMP mtime;

  /* Loop variables for the libpatterns value.  */
  char *p, *p2;
  int len;

  char *file, **dp;

  /* If we don't have libpatterns, get it.  */
  if (!libpatterns)
    {
      int save = warn_undefined_variables_flag;
      warn_undefined_variables_flag = 0;

      libpatterns = strdup (variable_expand ("$(strip $(.LIBPATTERNS))"));

      warn_undefined_variables_flag = save;
    }

  /* Loop through all the patterns in .LIBPATTERNS, and search on each one.  */
  p2 = libpatterns;
  while ((p = find_next_token (&p2, &len)) != 0)
    {
      static char *buf = NULL;
      static int buflen = 0;
      static int libdir_maxlen = -1;
      char *libbuf = variable_expand ("");

      /* Expand the pattern using LIBNAME as a replacement.  */
      {
	char c = p[len];
	char *p3, *p4;

	p[len] = '\0';
	p3 = find_percent (p);
	if (!p3)
	  {
	    /* Give a warning if there is no pattern, then remove the
	       pattern so it's ignored next time.  */
	    error (NILF, ".LIBPATTERNS element `%s' is not a pattern", p);
	    for (; len; --len, ++p)
	      *p = ' ';
	    *p = c;
	    continue;
	  }
	p4 = variable_buffer_output (libbuf, p, p3-p);
	p4 = variable_buffer_output (p4, libname, strlen (libname));
	p4 = variable_buffer_output (p4, p3+1, len - (p3-p));
	p[len] = c;
      }

      /* Look first for `libNAME.a' in the current directory.  */
      mtime = name_mtime (libbuf);
      if (mtime != (FILE_TIMESTAMP) -1)
	{
	  *lib = strdup (libbuf);
	  if (mtime_ptr != 0)
	    *mtime_ptr = mtime;
	  return 1;
	}

      /* Now try VPATH search on that.  */

      file = libbuf;
      if (vpath_search (&file, mtime_ptr))
	{
	  *lib = file;
	  return 1;
	}

      /* Now try the standard set of directories.  */

      if (!buflen)
	{
	  for (dp = dirs; *dp != 0; ++dp)
	    {
	      int l = strlen (*dp);
	      if (l > libdir_maxlen)
		libdir_maxlen = l;
	    }
	  buflen = strlen (libbuf);
	  buf = xmalloc(libdir_maxlen + buflen + 2);
	}
      else if (buflen < strlen (libbuf))
	{
	  buflen = strlen (libbuf);
	  buf = xrealloc (buf, libdir_maxlen + buflen + 2);
	}

      for (dp = dirs; *dp != 0; ++dp)
	{
	  sprintf (buf, "%s/%s", *dp, libbuf);
	  mtime = name_mtime (buf);
	  if (mtime != (FILE_TIMESTAMP) -1)
	    {
	      *lib = strdup (buf);
	      if (mtime_ptr != 0)
		*mtime_ptr = mtime;
	      return 1;
	    }
	}
    }

  return 0;
}
