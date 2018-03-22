  if (time_to_start_writing || access_mode == ACCESS_WRITE)
    flush_archive ();

  sys_drain_input_pipe ();
  
  if (verify_option)
    verify_volume ();

  if (rmtclose (archive) != 0)
    close_warn (*archive_name_cursor);

  sys_wait_for_child (child_pid);
  
  destroy_stat (&current_stat_info);
  if (save_name)
    free (save_name);
