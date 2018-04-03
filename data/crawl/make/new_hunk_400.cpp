      return;
    }

  print_cmd = (just_print_flag || trace_flag
               || (!(flags & COMMANDS_SILENT) && !silent_flag));

#ifdef OUTPUT_SYNC
  if (output_sync && sync_handle == -1)
    sync_init();
#endif

  /* Are we going to synchronize this command's output?  Do so if either we're
     in SYNC_MAKE mode or this command is not recursive.  We'll also check
     output_sync separately below in case it changes due to error.  */
  sync_cmd = output_sync && (output_sync == OUTPUT_SYNC_MAKE
                             || !(flags & COMMANDS_RECURSE));

#ifdef OUTPUT_SYNC
  if (sync_cmd)
    {
      /* If syncing, make sure we have temp files.
         Write the command to the temp file so it's output in order.  */
      assign_child_tempfiles (child);
      if (print_cmd)
        child_out (child, p, 1);
    }
  else
    /* We don't want to sync this command: to avoid misordered
       output ensure any already-synced content is written.  */
    sync_output (child);
#endif /* OUTPUT_SYNC */

  /* If we're not syncing, print out the command.  If silent, we call
     'message' with null so it can log the working directory before the
     command's own error messages appear.  */
  if (! sync_cmd)
    message (0, print_cmd ? "%s" : NULL, p);

  /* Tell update_goal_chain that a command has been started on behalf of
     this target.  It is important that this happens here and not in
