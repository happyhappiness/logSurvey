		    }
		  f = f->next;
		}
              if (exists)
                {
                  logputs (LOG_VERBOSE, "\n");
                  logprintf (LOG_NOTQUIET, _("File %s exists.\n"),
                             quote (u->file));
                }
	      else
                {
		  logputs (LOG_VERBOSE, "\n");
		  logprintf (LOG_NOTQUIET, _("No such file %s.\n"),
			     quote (u->file));
