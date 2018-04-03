      if (status != 0 && !keep_going_flag)
	return status;

      switch (f->command_state)
	{
	case cs_finished:
	  commands_finished |= not_started;
	  break;

	case cs_running:
	case cs_deps_running:
	  /* Don't run the other :: rules for this
	     file until this rule is finished.  */
	  return 0;

	default:
	  error ("internal error: `%s' command_state == %d in update_file_1",
		 f->name, (int) f->command_state);
	  abort ();
	  break;
	}
    }

  /* For a top level target, if we have found nothing whatever to do for it,
