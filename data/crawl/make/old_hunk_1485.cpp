      return;
    }

  /* Print out the command.  */

  if (just_print_flag || (!(flags & COMMANDS_SILENT) && !silent_flag))
    puts (p);

  /* Tell update_goal_chain that a command has been started on behalf of
     this target.  It is important that this happens here and not in
