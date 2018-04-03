      if (status != 0 && !keep_going_flag)
	return status;

      commands_finished |= not_started && f->command_state == cs_finished;
    }

  /* For a top level target, if we have found nothing whatever to do for it,
