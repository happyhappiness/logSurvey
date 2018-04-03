  return read_makefiles;
}

int
eval_makefile (filename, flags)
     char *filename;
     int flags;
{
  struct dep *deps;
  struct ebuffer ebuf;
  const struct floc *curfile;
  int makefile_errno;
  int r;

  ebuf.floc.filenm = filename;
  ebuf.floc.lineno = 1;

  if (ISDB (DB_VERBOSE))
    {
      printf (_("Reading makefile `%s'"), filename);
      if (flags & RM_NO_DEFAULT_GOAL)
	printf (_(" (no default goal)"));
      if (flags & RM_INCLUDED)
