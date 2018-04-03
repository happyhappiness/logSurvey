          child->file->update_status = us_success;
          notice_finished_file (child->file);
        }

      OUTPUT_UNSET();
      return;
    }

  /* Are we going to synchronize this command's output?  Do so if either we're
     in SYNC_RECURSE mode or this command is not recursive.  We'll also check
     output_sync separately below in case it changes due to error.  */
  child->output.syncout = output_sync && (output_sync == OUTPUT_SYNC_RECURSE
                                          || !(flags & COMMANDS_RECURSE));

  OUTPUT_SET (&child->output);

#ifdef OUTPUT_SYNC
  if (! child->output.syncout)
    /* We don't want to sync this command: to avoid misordered
       output ensure any already-synced content is written.  */
    output_dump (&child->output);
#endif /* OUTPUT_SYNC */

  /* Print the command if appropriate.  */
  if (just_print_flag || trace_flag
      || (!(flags & COMMANDS_SILENT) && !silent_flag))
    message (0, "%s", p);

  /* Tell update_goal_chain that a command has been started on behalf of
     this target.  It is important that this happens here and not in
