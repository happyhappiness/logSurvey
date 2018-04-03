
  for (f = file; f != 0; f = f->prev)
    {
      register struct dep *d;
      int not_started = f->command_state == cs_not_started;

      status |= update_file_1 (f, depth);
      check_renamed (f);

      for (d = f->also_make; d != 0; d = d->next)
	{
	  check_renamed (d->file);
	  d->file->command_state = f->command_state;
	  d->file->update_status = f->update_status;
	  d->file->updated = f->updated;
	  if (debug_flag)
	    {
	      print_spaces (depth);
	      printf ("File `%s' was also made by making `%s'.\n",
		      d->file->name, f->name);
	    }
	}

      if (status != 0 && !keep_going_flag)
	return status;

