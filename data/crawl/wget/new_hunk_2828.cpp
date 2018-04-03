			  ? CONERROR : CONIMPOSSIBLE);
		}

	      pasv_mode_open = true;  /* Flag to avoid accept port */
	      if (!opt.server_response)
		logputs (LOG_VERBOSE, _("done.    "));
	    } /* err==FTP_OK */
