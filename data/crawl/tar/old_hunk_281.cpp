      if (errno == ENOENT)
	return 1;

      ERROR ((0, errno, "%s", path));
      return 0;
    }

  if (S_ISDIR (file_stat.st_mode))
    return 1;

#ifdef S_ISBLK
  if (archive && S_ISBLK (file_stat.st_mode))
    return 1;
#endif

#ifdef S_ISCHR
  if (archive && S_ISCHR (file_stat.st_mode))
    return 1;
#endif

  assign_string (&before_backup_name, path);

