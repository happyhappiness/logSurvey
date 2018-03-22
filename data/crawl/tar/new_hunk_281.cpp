      if (errno == ENOENT)
	return 1;

      stat_error (path);
      return 0;
    }

  if (S_ISDIR (file_stat.st_mode))
    return 1;

  if (archive && (S_ISBLK (file_stat.st_mode) || S_ISCHR (file_stat.st_mode)))
    return 1;

  assign_string (&before_backup_name, path);

