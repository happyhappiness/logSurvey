		  break;

		default:
		  error ("internal error: `%s' command_state \
%d in child_handler", c->file->name);
		  abort ();
		  break;
		}
	    }

	  /* Set the state flag to say the commands have finished.  */
	  notice_finished_file (c->file);

	  /* Remove the child from the chain and free it.  */
