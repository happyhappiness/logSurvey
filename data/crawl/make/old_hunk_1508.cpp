			 by start_remote_job_p.  */
		      c->remote = start_remote_job_p ();
		      start_job_command (c);
		    }
		}

	      switch (c->file->command_state)
		{
		case cs_running:
		  /* Successfully started.  Loop to reap more children.  */
		  continue;

		case cs_finished:
		  if (c->file->update_status != 0)
		    /* We failed to start the commands.  */
		    delete_child_targets (c);
		  break;

		default:
		  error ("internal error: `%s' has bogus command_state \
%d in reap_children",
			 c->file->name, (int) c->file->command_state);
		  abort ();
		  break;
		}
	    }

	  if (! handling_fatal_signal)
	    /* Notice if the target of the commands has been changed.
	       This also propagates its values for command_state and
