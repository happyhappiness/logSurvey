  free (sparsearray);

  if (different)
    report_difference (_("Data differs"));
}

/*---------------------------------------------------------------------.
| Call either stat or lstat over STAT_DATA, depending on --dereference |
| (-h), for a file which should exist.  Diagnose any problem.  Return  |
| nonzero for success, zero otherwise.				       |
`---------------------------------------------------------------------*/

static int
get_stat_data (struct stat *stat_data)
{
  int status = (dereference_option
		? stat (current_file_name, stat_data)
		: lstat (current_file_name, stat_data));

  if (status < 0)
    {
      if (errno == ENOENT)
	report_difference (_("File does not exist"));
      else
	{
	  ERROR ((0, errno, _("Cannot stat file %s"), current_file_name));
	  report_difference (NULL);
	}
#if 0
      skip_file ((long) current_stat.st_size);
#endif
      return 0;
    }

  return 1;
}

/*----------------------------------.
| Diff a file against the archive.  |
`----------------------------------*/

void
diff_archive (void)
{
  struct stat stat_data;
  int name_length;
  int status;

  errno = EPIPE;		/* FIXME: errno should be read-only */
				/* FIXME: remove perrors */

  set_next_block_after (current_header);
  decode_header (current_header, &current_stat, &current_format, 1);

  /* Print the block from `current_header' and `current_stat'.  */

  if (verbose_option)
    {
      if (now_verifying)
	fprintf (stdlis, _("Verify "));
      print_header ();
    }

  switch (current_header->header.typeflag)
    {
    default:
      WARN ((0, 0, _("Unknown file type '%c' for %s, diffed as normal file"),
		 current_header->header.typeflag, current_file_name));
      /* Fall through.  */

    case AREGTYPE:
