	  break;

      if (c == 0)
	{
	  /* An unknown child died.
             Ignore it; it was inherited from our invoker.  */
          continue;
	}
      else
	{
	  if (debug_flag)
	    printf ("Reaping %s child 0x%08lx PID %ld token %c%s\n",
		    child_failed ? "losing" : "winning",
		    (unsigned long int) c, (long) c->pid, c->job_token,
                    c->remote ? " (remote)" : "");

          if (c->sh_batch_file) {
            if (debug_flag)
              printf("Cleaning up temp batch file %s\n", c->sh_batch_file);

            /* just try and remove, don't care if this fails */
            remove(c->sh_batch_file);

            /* all done with memory */
            free(c->sh_batch_file);
            c->sh_batch_file = NULL;
          }

	  /* If this child had the good stdin, say it is now free.  */
	  if (c->good_stdin)
	    good_stdin_used = 0;

	  if (child_failed && !c->noerror && !ignore_errors_flag)
	    {
	      /* The commands failed.  Write an error message,
		 delete non-precious targets, and abort.  */
	      static int delete_on_error = -1;
	      child_error (c->file->name, exit_code, exit_sig, coredump, 0);
	      c->file->update_status = 2;
	      if (delete_on_error == -1)
		{
		  struct file *f = lookup_file (".DELETE_ON_ERROR");
		  delete_on_error = f != 0 && f->is_target;
		}
	      if (exit_sig != 0 || delete_on_error)
		delete_child_targets (c);
	    }
	  else
	    {
	      if (child_failed)
		{
		  /* The commands failed, but we don't care.  */
		  child_error (c->file->name,
			       exit_code, exit_sig, coredump, 1);
		  child_failed = 0;
		}

	      /* If there are more commands to run, try to start them.  */
	      if (job_next_command (c))
		{
		  if (handling_fatal_signal)
		    {
		      /* Never start new commands while we are dying.
			 Since there are more commands that wanted to be run,
			 the target was not completely remade.  So we treat
			 this as if a command had failed.  */
		      c->file->update_status = 2;
		    }
		  else
		    {
		      /* Check again whether to start remotely.
			 Whether or not we want to changes over time.
			 Also, start_remote_job may need state set up
			 by start_remote_job_p.  */
		      c->remote = start_remote_job_p (0);
		      start_job_command (c);
		      /* Fatal signals are left blocked in case we were
			 about to put that child on the chain.  But it is
			 already there, so it is safe for a fatal signal to
			 arrive now; it will clean up this child's targets.  */
		      unblock_sigs ();
		      if (c->file->command_state == cs_running)
			/* We successfully started the new command.
			   Loop to reap more children.  */
			continue;
		    }

		  if (c->file->update_status != 0)
		    /* We failed to start the commands.  */
		    delete_child_targets (c);
		}
	      else
		/* There are no more commands.  We got through them all
		   without an unignored error.  Now the target has been
		   successfully updated.  */
		c->file->update_status = 0;
	    }

	  /* When we get here, all the commands for C->file are finished
	     (or aborted) and C->file->update_status contains 0 or 2.  But
	     C->file->command_state is still cs_running if all the commands
	     ran; notice_finish_file looks for cs_running to tell it that
	     it's interesting to check the file's modtime again now.  */

	  if (! handling_fatal_signal)
	    /* Notice if the target of the commands has been changed.
	       This also propagates its values for command_state and
	       update_status to its also_make files.  */
	    notice_finished_file (c->file);

	  if (debug_flag)
	    printf ("Removing child 0x%08lx PID %ld token %c%s from chain.\n",
		    (unsigned long int) c, (long) c->pid, c->job_token,
                    c->remote ? " (remote)" : "");

	  /* Block fatal signals while frobnicating the list, so that
	     children and job_slots_used are always consistent.  Otherwise
	     a fatal signal arriving after the child is off the chain and
	     before job_slots_used is decremented would believe a child was
	     live and call reap_children again.  */
	  block_sigs ();

	  /* If this job has a token out, return it.  */
          free_job_token(c);

	  /* There is now another slot open.  */
	  if (job_slots_used > 0)
	    --job_slots_used;

	  /* Remove the child from the chain and free it.  */
	  if (lastc == 0)
	    children = c->next;
	  else
	    lastc->next = c->next;
	  if (! handling_fatal_signal) /* Don't bother if about to die.  */
	    free_child (c);

	  unblock_sigs ();

	  /* If the job failed, and the -k flag was not given, die,
	     unless we are already in the process of dying.  */
	  if (!err && child_failed && !keep_going_flag &&
	      /* fatal_error_signal will die with the right signal.  */
	      !handling_fatal_signal)
	    die (2);
	}

      /* Only block for one child.  */
      block = 0;
    }
  return;
}

