		  break;

		default:
		  error ("internal error: `%s' has bogus command_state \
%d in reap_children",
			 c->file->name, c->file->command_state);
		  abort ();
		  break;
		}
	    }

	  /* Notice if the target of the commands has been changed.  */
	  notice_finished_file (c->file);

	  /* Remove the child from the chain and free it.  */
