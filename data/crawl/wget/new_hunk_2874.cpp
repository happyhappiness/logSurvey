	  post_data_size = file_size (opt.post_file_name);
	  if (post_data_size == -1)
	    {
	      logprintf (LOG_NOTQUIET, _("POST data file missing: %s (%s)\n"),
			 opt.post_file_name, strerror (errno));
	      post_data_size = 0;
	    }
	}
