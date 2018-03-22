  skipcrud = 0;
  if (! absolute_names_option)
    {
      if (contains_dot_dot (CURRENT_FILE_NAME))
	{
	  ERROR ((0, 0, _("%s: Member name contains `..'"),
		  quotearg_colon (CURRENT_FILE_NAME)));
	  skip_member ();
	  return;
	}

      skipcrud = FILESYSTEM_PREFIX_LEN (current_file_name);
      while (ISSLASH (CURRENT_FILE_NAME[0]))
	skipcrud++;

      if (skipcrud)
	{
	  static int warned_once;
	  
	  if (!warned_once)
	    {
	      warned_once = 1;
	      WARN ((0, 0, _("Removing leading `%.*s' from member names"),
		     (int) skipcrud, current_file_name));
	    }
	}
    }

