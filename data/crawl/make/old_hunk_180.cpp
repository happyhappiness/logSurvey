  /* Print the command if appropriate.  */
  if (just_print_flag || trace_flag
      || (!(flags & COMMANDS_SILENT) && !silent_flag))
    message (0, "%s", p);

  /* Tell update_goal_chain that a command has been started on behalf of
     this target.  It is important that this happens here and not in
