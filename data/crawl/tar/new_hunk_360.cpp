  /* Check for fully specified file names and other atrocities.  */

  skipcrud = 0;
  if (! absolute_names_option)
    {
      while (CURRENT_FILE_NAME[0] == '/')
	{
	  static int warned_once;
	  
	  if (!warned_once)
	    {
	      warned_once = 1;
	      WARN ((0, 0, _("Removing leading `/' from member names")));
	    }
	  skipcrud++;		/* force relative path */
	}

      if (contains_dot_dot (CURRENT_FILE_NAME))
	{
	  ERROR ((0, 0, _("%s: Member name contains `..'"),
		  quotearg_colon (CURRENT_FILE_NAME)));
	  if (current_header->oldgnu_header.isextended)
	    skip_extended_headers ();
	  skip_file (current_stat.st_size);
	  return;
	}
    }

  /* Take a safety backup of a previously existing file.  */
