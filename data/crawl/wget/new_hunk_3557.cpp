/* Return the directory listing in a reusable format.  The directory
   is specifed in u->dir.  */
uerr_t
ftp_get_listing (struct url *u, ccon *con, struct fileinfo **f)
{
  uerr_t err;
  char *uf;			/* url file name */
  char *lf;			/* list file name */
  char *old_target = con->target;

  con->st &= ~ON_YOUR_OWN;
  con->cmd |= (DO_LIST | LEAVE_PENDING);
  con->cmd &= ~DO_RETR;

  /* Find the listing file name.  We do it by taking the file name of
     the URL and replacing the last component with the listing file
     name.  */
  uf = url_filename (u);
  lf = file_merge (uf, LIST_FILENAME);
  xfree (uf);
  DEBUGP ((_("Using `%s' as listing tmp file.\n"), lf));

  con->target = lf;
  err = ftp_loop_internal (u, NULL, con);
  con->target = old_target;

  if (err == RETROK)
    *f = ftp_parse_ls (lf, con->rs);
  else
    *f = NULL;
  if (opt.remove_listing)
    {
      if (unlink (lf))
	logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
      else
	logprintf (LOG_VERBOSE, _("Removed `%s'.\n"), lf);
    }
  xfree (lf);
  con->cmd &= ~DO_LIST;
  return err;
}

static uerr_t ftp_retrieve_dirs PARAMS ((struct url *, struct fileinfo *,
					 ccon *));
static uerr_t ftp_retrieve_glob PARAMS ((struct url *, ccon *, int));
static struct fileinfo *delelement PARAMS ((struct fileinfo *,
					    struct fileinfo **));
static void freefileinfo PARAMS ((struct fileinfo *f));
