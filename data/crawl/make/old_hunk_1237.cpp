      0
    };

  char *libname = &(*lib)[2];	/* Name without the `-l'.  */
  FILE_TIMESTAMP mtime;

  /* Buffer to construct possible names in.  */
  char *buf = xmalloc (sizeof (LIBDIR) + 8 + strlen (libname) + 4 + 2 + 1);
  char *file, **dp;

  /* Look first for `libNAME.a' in the current directory.  */

#ifndef _AMIGA
  sprintf (buf, "lib%s.a", libname);
#else
  sprintf (buf, "%s.lib", libname);
#endif
  mtime = name_mtime (buf);
  if (mtime != (FILE_TIMESTAMP) -1)
    {
      *lib = buf;
      if (mtime_ptr != 0)
	*mtime_ptr = mtime;
      return 1;
    }

  /* Now try VPATH search on that.  */

  file = buf;
  if (vpath_search (&file, mtime_ptr))
    {
      free (buf);
      *lib = file;
      return 1;
    }

  /* Now try the standard set of directories.  */

#ifdef  __MSDOS__
  {
    /* The default library directory is at ${DJDIR}/lib.  */
    struct variable *djdir = lookup_variable ("DJDIR", 5);

    if (djdir)
      {
	size_t djdir_len = strlen (djdir->value);

	if (djdir_len > sizeof(LIBDIR) + 8 + strlen(libname) + 4 + 2)
	  buf = (char *) xrealloc (djdir_len + 1);
	sprintf (buf, "%s/lib/lib%s.a", djdir->value, libname);
	mtime = name_mtime (buf);
	if (mtime != (FILE_TIMESTAMP) -1)
	  {
	    *lib = buf;
	    if (mtime_ptr != 0)
	      *mtime_ptr = mtime;
	    return 1;
	  }
      }
  }
#endif

  for (dp = dirs; *dp != 0; ++dp)
    {
#ifndef _AMIGA
      sprintf (buf, "%s/lib%s.a", *dp, libname);
#else
      sprintf (buf, "%s/%s.lib", *dp, libname);
#endif
      mtime = name_mtime (buf);
      if (mtime != (FILE_TIMESTAMP) -1)
	{
	  *lib = buf;
	  if (mtime_ptr != 0)
	    *mtime_ptr = mtime;
	  return 1;
	}
    }

  free (buf);
  return 0;
}
