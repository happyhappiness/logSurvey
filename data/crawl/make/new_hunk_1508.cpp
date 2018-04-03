			 by start_remote_job_p.  */
		      c->remote = start_remote_job_p ();
		      start_job_command (c);
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
	     (or aborted) and C->file->update_status contains 0 or 1.  But
	     C->file->command_state is still cs_running if all the commands
	     ran; notice_finish_file looks for cs_running to tell it that
	     it's interesting to check the file's modtime again now.  */

	  if (! handling_fatal_signal)
	    /* Notice if the target of the commands has been changed.
	       This also propagates its values for command_state and
