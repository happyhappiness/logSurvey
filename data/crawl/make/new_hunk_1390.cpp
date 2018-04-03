  message (0, (just_print_flag || (!(flags & COMMANDS_SILENT) && !silent_flag))
	   ? "%s" : (char *) 0, p);

  /* Optimize an empty command.  People use this for timestamp rules,
     and forking a useless shell all the time leads to inefficiency. */

  if ((argv[0]      && !strcmp(argv[0], "/bin/sh"))
      && (argv[1]   && !strcmp(argv[1], "-c"))
      && (argv[2]   && !strcmp(argv[2], ":"))
      && argv[3] == NULL)
    {
      set_command_state (child->file, cs_running);
      goto next_command;
    }

  /* Tell update_goal_chain that a command has been started on behalf of
     this target.  It is important that this happens here and not in
     reap_children (where we used to do it), because reap_children might be
