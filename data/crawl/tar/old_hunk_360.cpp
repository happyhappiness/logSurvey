  /* Check for fully specified file names and other atrocities.  */

  skipcrud = 0;
  while (!absolute_names_option && CURRENT_FILE_NAME[0] == '/')
    {
      static int warned_once;

      if (!warned_once)
	{
	  warned_once = 1;
	  WARN ((0, 0, _("Removing leading `/' from archive names")));
	}
      skipcrud++;		/* force relative path */
    }

  /* Take a safety backup of a previously existing file.  */
