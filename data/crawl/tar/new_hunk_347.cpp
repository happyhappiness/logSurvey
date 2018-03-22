
  if (handle < 0)
    {
      open_error (path);
      return;
    }

  if (fstat (handle, &stat_data) != 0)
    stat_error (path);
  else
    {
      off_t bytes_left = stat_data.st_size;
