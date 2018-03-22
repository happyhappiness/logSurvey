static void
set_mode (char *file_name, struct stat *stat_info)
{
  /* We ought to force permission when -k is not selected, because if the
     file already existed, open or creat would save the permission bits from
     the previously created file, ignoring the ones we specified.

     But with -k selected, we know *we* created this file, so the mode
     bits were set by our open.  If the file has abnormal mode bits, we must
     chmod since writing or chown has probably reset them.  If the file is
     normal, we merely skip the chmod.  This works because we did umask (0)
     when -p, so umask will have left the specified mode alone.  */

  if (!keep_old_files_option
      || (stat_info->st_mode & (S_ISUID | S_ISGID | S_ISVTX)))
    if (chmod (file_name, ~current_umask & stat_info->st_mode) < 0)
      ERROR ((0, errno, _("%s: Cannot change mode to %04lo"),
	      file_name,
