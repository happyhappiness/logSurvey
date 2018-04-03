
  for (f = file; f != 0; f = f->prev)
    {
      int not_started = f->command_state == cs_not_started;

      status |= update_file_1 (f, depth);
      check_renamed (f);

      if (status != 0 && !keep_going_flag)
	return status;

