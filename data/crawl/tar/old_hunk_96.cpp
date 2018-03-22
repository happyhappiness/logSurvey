
  if (dumpdir_buffer)
    {
      dumpdir_cursor = dumpdir_buffer;
      read_and_process (&current_stat_info, process_dumpdir);
      free (dumpdir_buffer);
    }
  else
    read_and_process (&current_stat_info, process_noop);
