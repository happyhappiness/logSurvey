
      if (check_for_renamed_directories)
	{
	  cur_info = &st;
	  if (stat (data->file_name, &st) != 0)
	    {
	      stat_error (data->file_name);
	      skip_this_one = 1;
	    }
	  else if (! (st.st_dev == data->dev && st.st_ino == data->ino))
	    {
	      ERROR ((0, 0,
		      _("%s: Directory renamed before its status could be extracted"),
		      quotearg_colon (data->file_name)));
	      skip_this_one = 1;
	    }
	}

