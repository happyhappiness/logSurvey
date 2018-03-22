}

static void
diff_dumpdir (void)
{
  const char *dumpdir_buffer;
  dev_t dev = 0;
  struct stat stat_data;

  if (deref_stat (current_stat_info.file_name, &stat_data) != 0)
    {
      if (errno == ENOENT)
	stat_warn (current_stat_info.file_name);
      else
	stat_error (current_stat_info.file_name);
    }
  else
    dev = stat_data.st_dev;

  dumpdir_buffer = directory_contents (scan_directory (&current_stat_info));

  if (dumpdir_buffer)
    {
      if (dumpdir_cmp (current_stat_info.dumpdir, dumpdir_buffer))
	report_difference (&current_stat_info, _("Contents differ"));
    }
  else
    read_and_process (&current_stat_info, process_noop);
}

static void
