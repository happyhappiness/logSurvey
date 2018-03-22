  if (!keep_old_files_option
      || (stat_info->st_mode & (S_ISUID | S_ISGID | S_ISVTX)))
    if (chmod (file_name, ~current_umask & stat_info->st_mode) < 0)
      ERROR ((0, errno, _("%s: Cannot change mode to %0.4lo"),
	      file_name,
	      (unsigned long) (~current_umask & stat_info->st_mode)));
}
