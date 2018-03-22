    }
#endif

  if (S_ISDIR (current_stat.st_mode))
    {
      DIR *directory;
      struct dirent *entry;
