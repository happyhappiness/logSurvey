    return buffer;
  }
}

static FILE *listed_incremental_stream;

void
read_directory_file (void)
{
  int fd;
  FILE *fp;
  char *buf = 0;
  size_t bufsize;

  /* Open the file for both read and write.  That way, we can write
     it later without having to reopen it, and don't have to worry if
     we chdir in the meantime.  */
  fd = open (listed_incremental_option, O_RDWR | O_CREAT, MODE_RW);
  if (fd < 0)
    {
      open_error (listed_incremental_option);
      return;
    }

  fp = fdopen (fd, "r+");
  if (! fp)
    {
      open_error (listed_incremental_option);
      close (fd);
      return;
    }

  listed_incremental_stream = fp;

  if (0 < getline (&buf, &bufsize, fp))
    {
      char *ebuf;
      int n;
      long lineno = 1;
      unsigned long u = (errno = 0, strtoul (buf, &ebuf, 10));
      time_t t = u;
      if (buf == ebuf || (u == 0 && errno == EINVAL))
	ERROR ((0, 0, "%s:1: %s", quotearg_colon (listed_incremental_option),
		_("Invalid time stamp")));
      else if (t != u || (u == -1 && errno == ERANGE))
	ERROR ((0, 0, "%s:1: %s", quotearg_colon (listed_incremental_option),
		_("Time stamp out of range")));
      else
	newer_mtime_option = t;

      while (0 < (n = getline (&buf, &bufsize, fp)))
	{
	  dev_t dev;
	  ino_t ino;
	  bool nfs = buf[0] == '+';
	  char *strp = buf + nfs;

	  lineno++;

	  if (buf[n - 1] == '\n')
	    buf[n - 1] = '\0';

	  errno = 0;
	  dev = u = strtoul (strp, &ebuf, 10);
	  if (strp == ebuf || (u == 0 && errno == EINVAL))
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Invalid device number")));
	  else if (dev != u || (u == -1 && errno == ERANGE))
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Device number out of range")));
	  strp = ebuf;

	  errno = 0;
	  ino = u = strtoul (strp, &ebuf, 10);
	  if (strp == ebuf || (u == 0 && errno == EINVAL))
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Invalid inode number")));
	  else if (ino != u || (u == -1 && errno == ERANGE))
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Inode number out of range")));
	  strp = ebuf;

	  strp++;
	  unquote_string (strp);
	  note_directory (strp, dev, ino, nfs, 0);
	}
    }

  if (ferror (fp))
    read_error (listed_incremental_option);
  if (buf)
    free (buf);
}

/* Output incremental data for the directory ENTRY to the file DATA.
   Return nonzero if successful, preserving errno on write failure.  */
static bool
write_directory_file_entry (void *entry, void *data)
{
  struct directory const *directory = entry;
  FILE *fp = data;

  if (directory->found)
    {
      int e;
      char *str = quote_copy_string (directory->name);
      fprintf (fp, "+%lu %lu %s\n" + ! directory->nfs,
	       (unsigned long) directory->device_number,
	       (unsigned long) directory->inode_number,
	       str ? str : directory->name);
      e = errno;
      if (str)
	free (str);
      errno = e;
    }

  return ! ferror (fp);
}

void
write_directory_file (void)
{
  FILE *fp = listed_incremental_stream;

  if (! fp)
    return;

  if (fseek (fp, 0L, SEEK_SET) != 0)
    seek_error (listed_incremental_option);
  if (ftruncate (fileno (fp), (off_t) 0) != 0)
    truncate_error (listed_incremental_option);

  fprintf (fp, "%lu\n", (unsigned long) start_time);
  if (! ferror (fp) && directory_table)
    hash_do_for_each (directory_table, write_directory_file_entry, fp);
  if (ferror (fp))
    write_error (listed_incremental_option);
  if (fclose (fp) != 0)
    close_error (listed_incremental_option);
}

/* Restoration of incremental dumps.  */

void
gnu_restore (char const *directory_name)
{
  char *archive_dir;
  char *current_dir;
  char *cur, *arc;
  size_t size;
  size_t copied;
  union block *data_block;
  char *to;

  current_dir = savedir (directory_name);

  if (!current_dir)
    {
      /* The directory doesn't exist now.  It'll be created.  In any
	 case, we don't have to delete any files out of it.  */

      skip_member ();
      return;
    }

  size = current_stat_info.stat.st_size;
  if (size != current_stat_info.stat.st_size)
    xalloc_die ();
  archive_dir = xmalloc (size);
  to = archive_dir;
  for (; size > 0; size -= copied)
    {
      data_block = find_next_block ();
      if (!data_block)
