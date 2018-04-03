   ftp_retrieve_glob on each directory entry.  The function knows
   about excluded directories.  */
static uerr_t
ftp_retrieve_dirs (struct urlinfo *u, struct fileinfo *f, ccon *con)
{
  char *odir;
  char *current_container = NULL;
  int current_length = 0;

  for (; f; f = f->next)
    {
      int len;

      if (downloaded_exceeds_quota ())
	break;
      if (f->type != FT_DIRECTORY)
	continue;
      odir = u->dir;
      len = strlen (u->dir) + 1 + strlen (f->name) + 1;
      /* Allocate u->dir off stack, but reallocate only if a larger
         string is needed.  */
      if (len > current_length)
	current_container = (char *)alloca (len);
      u->dir = current_container;
      if (*odir == '\0'
	  || (*odir == '/' && *(odir + 1) == '\0'))
	/* If ODIR is empty or just "/", simply append f->name to
	   ODIR.  (In the former case, to preserve u->dir being
	   relative; in the latter case, to avoid double slash.)  */
	sprintf (u->dir, "%s%s", odir, f->name);
      else
	/* Else, use a separator. */
	sprintf (u->dir, "%s/%s", odir, f->name);
      DEBUGP (("Composing new CWD relative to the initial directory.\n"));
      DEBUGP (("  odir = '%s'\n  f->name = '%s'\n  u->dir = '%s'\n\n",
	       odir, f->name, u->dir));
      if (!accdir (u->dir, ALLABS))
	{
	  logprintf (LOG_VERBOSE, _("\
Not descending to `%s' as it is excluded/not-included.\n"), u->dir);
	  u->dir = odir;
	  continue;
	}
      con->st &= ~DONE_CWD;
      ftp_retrieve_glob (u, con, GETALL);
      /* Set the time-stamp?  */
      u->dir = odir;
    }
  if (opt.quota && opt.downloaded > opt.quota)
    return QUOTEXC;
  else
