  free (sparsearray);

  if (different)
    report_difference (_("Contents differ"));
}

/* Call either stat or lstat over STAT_DATA, depending on
   --dereference (-h), for a file which should exist.  Diagnose any
   problem.  Return nonzero for success, zero otherwise.  */
static int
get_stat_data (char const *file_name, struct stat *stat_data)
{
  int status = deref_stat (dereference_option, file_name, stat_data);

  if (status != 0)
    {
      if (errno == ENOENT)
	stat_warn (file_name);
      else
	stat_error (file_name);
      report_difference (0);
      return 0;
    }

  return 1;
}

/* Diff a file against the archive.  */
void
diff_archive (void)
{
  struct stat stat_data;
  int status;
  struct utimbuf restore_times;

  set_next_block_after (current_header);
  decode_header (current_header, &current_stat_info, &current_format, 1);

  /* Print the block from current_header and current_stat_info.  */

  if (verbose_option)
    {
      if (now_verifying)
	fprintf (stdlis, _("Verify "));
      print_header (-1);
    }

  switch (current_header->header.typeflag)
    {
    default:
      ERROR ((0, 0, _("%s: Unknown file type '%c', diffed as normal file"),
	      quotearg_colon (current_stat_info.file_name),
	      current_header->header.typeflag));
      /* Fall through.  */

    case AREGTYPE:
