
  if (handle < 0)
    {
      ERROR ((0, errno, _("Cannot open file %s"), path));
      return;
    }

  if (fstat (handle, &stat_data) != 0)
    ERROR ((0, errno, "%s", path));
  else
    {
      off_t bytes_left = stat_data.st_size;
