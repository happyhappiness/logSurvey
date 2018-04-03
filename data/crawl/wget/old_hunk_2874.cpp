	  post_data_size = file_size (opt.post_file_name);
	  if (post_data_size == -1)
	    {
	      logprintf (LOG_NOTQUIET, "POST data file missing: %s\n",
			 opt.post_file_name);
	      post_data_size = 0;
	    }
	}
