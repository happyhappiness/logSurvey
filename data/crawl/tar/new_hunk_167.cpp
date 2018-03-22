  return 1;
}


static void
diff_dir ()
{
  struct stat stat_data;

  if (!get_stat_data (current_stat_info.file_name, &stat_data))
    return;

  if (!S_ISDIR (stat_data.st_mode))
    report_difference (&current_stat_info, _("File type differs"));
  else if ((current_stat_info.stat.st_mode & MODE_ALL) !=
	   (stat_data.st_mode & MODE_ALL))
    report_difference (&current_stat_info, _("Mode differs"));
}

static void
diff_file ()
{
  struct stat stat_data;

  if (!get_stat_data (current_stat_info.file_name, &stat_data))
    skip_member ();
  else if (!S_ISREG (stat_data.st_mode))
    {
      report_difference (&current_stat_info, _("File type differs"));
      skip_member ();
    }
  else
    {
      if ((current_stat_info.stat.st_mode & MODE_ALL) !=
	  (stat_data.st_mode & MODE_ALL))
	report_difference (&current_stat_info, _("Mode differs"));
