    char name[1];
  };

struct link *linklist;		/* Points to first link in list */

static nolinks;			/* Gets set if we run out of RAM */

/*
 * "Scratch" space to store the information about a sparse file before
 * writing the info into the header or extended header
 */
/* struct sp_array	 *sparsearray;*/

/* number of elts storable in the sparsearray */
/*int 	sparse_array_size = 10;*/

void
create_archive ()
{
  register char *p;
  char *name_from_list ();

  open_archive (0);		/* Open for writing */

  if (f_gnudump)
    {
      char *buf = ck_malloc (PATH_MAX);
      char *q, *bufp;

      collect_and_sort_names ();

      while (p = name_from_list ())
	dump_file (p, -1, 1);
      /* if(!f_dironly) { */
      blank_name_list ();
      while (p = name_from_list ())
	{
	  strcpy (buf, p);
	  if (p[strlen (p) - 1] != '/')
	    strcat (buf, "/");
	  bufp = buf + strlen (buf);
	  for (q = gnu_list_name->dir_contents; q && *q; q += strlen (q) + 1)
	    {
	      if (*q == 'Y')
		{
		  strcpy (bufp, q + 1);
		  dump_file (buf, -1, 1);
		}
	    }
	}
      /* } */
      free (buf);
    }
  else
    {
      while (p = name_next (1))
	dump_file (p, -1, 1);
    }

  write_eot ();
  close_archive ();
  if (f_gnudump)
    write_dir_file ();
  name_close ();
}

/*
 * Dump a single file.  If it's a directory, recurse.
 * Result is 1 for success, 0 for failure.
 * Sets global "hstat" to stat() output for this file.
 */
void
dump_file (p, curdev, toplevel)
     char *p;			/* File name to dump */
     int curdev;		/* Device our parent dir was on */
     int toplevel;		/* Whether we are a toplevel call */
{
  union record *header;
  char type;
  extern char *save_name;	/* JF for multi-volume support */
  extern long save_totsize;
  extern long save_sizeleft;
  union record *exhdr;
  char save_linkflag;
  extern time_t new_time;
  int critical_error = 0;
  struct utimbuf restore_times;
  /*	int sparse_ind = 0;*/


  if (f_confirm && !confirm ("add", p))
    return;

  /*
	 * Use stat if following (rather than dumping) 4.2BSD's
	 * symbolic links.  Otherwise, use lstat (which, on non-4.2
	 * systems, is #define'd to stat anyway.
	 */
#ifdef STX_HIDDEN		/* AIX */
  if (0 != f_follow_links ?
      statx (p, &hstat, STATSIZE, STX_HIDDEN) :
      statx (p, &hstat, STATSIZE, STX_HIDDEN | STX_LINK))
#else
  if (0 != f_follow_links ? stat (p, &hstat) : lstat (p, &hstat))
#endif
    {
    badperror:
      msg_perror ("can't add file %s", p);
    badfile:
      if (!f_ignore_failed_read || critical_error)
	errors++;
      return;
    }

  restore_times.actime = hstat.st_atime;
  restore_times.modtime = hstat.st_mtime;

#ifdef S_ISHIDDEN
  if (S_ISHIDDEN (hstat.st_mode))
    {
      char *new = (char *) alloca (strlen (p) + 2);
      if (new)
