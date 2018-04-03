/* Return the directory listing in a reusable format.  The directory
   is specifed in u->dir.  */
uerr_t
ftp_get_listing (struct urlinfo *u, ccon *con, struct fileinfo **f)
{
  uerr_t err;
  char *olocal = u->local;
  char *list_filename, *ofile;

  con->st &= ~ON_YOUR_OWN;
  con->cmd |= (DO_LIST | LEAVE_PENDING);
  con->cmd &= ~DO_RETR;
  /* Get the listing filename.  */
  ofile = u->file;
  u->file = LIST_FILENAME;
  list_filename = url_filename (u);
  u->file = ofile;
  u->local = list_filename;
  DEBUGP ((_("Using `%s' as listing tmp file.\n"), list_filename));
  err = ftp_loop_internal (u, NULL, con);
  u->local = olocal;
  if (err == RETROK)
    *f = ftp_parse_ls (list_filename, con->rs);
  else
    *f = NULL;
  if (opt.remove_listing)
    {
      if (unlink (list_filename))
	logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
      else
	logprintf (LOG_VERBOSE, _("Removed `%s'.\n"), list_filename);
    }
  xfree (list_filename);
  con->cmd &= ~DO_LIST;
  return err;
}

static uerr_t ftp_retrieve_dirs PARAMS ((struct urlinfo *, struct fileinfo *,
					 ccon *));
static uerr_t ftp_retrieve_glob PARAMS ((struct urlinfo *, ccon *, int));
static struct fileinfo *delelement PARAMS ((struct fileinfo *,
					    struct fileinfo **));
static void freefileinfo PARAMS ((struct fileinfo *f));
