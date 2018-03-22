process_rawdata (size_t bytes, char *buffer)
{
  ssize_t status = safe_read (diff_handle, diff_buffer, bytes);

  if (status != bytes)
    {
      if (status < 0)
	{
	  read_error (current_stat_info.file_name);
	  report_difference (NULL);
	}
      else
	{
	  report_difference (ngettext ("Could only read %lu of %lu byte",
				       "Could only read %lu of %lu bytes",
				       bytes),
			     (unsigned long) status, (unsigned long) bytes);
	}
      return 0;
    }
