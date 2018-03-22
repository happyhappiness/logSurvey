#if !MSDOS
    case LNKTYPE:
      {
	dev_t dev;
	ino_t ino;

	if (!get_stat_data (&stat_data))
	  break;

	dev = stat_data.st_dev;
	ino = stat_data.st_ino;
	status = stat (current_link_name, &stat_data);
	if (status < 0)
	  {
	    if (errno == ENOENT)
	      report_difference (_("Does not exist"));
	    else
	      {
		WARN ((0, errno, _("Cannot stat file %s"), current_file_name));
		report_difference (NULL);
	      }
	    break;
	  }

	if (stat_data.st_dev != dev || stat_data.st_ino != ino)
	  {
	    char *message = (char *)
	      xmalloc (MESSAGE_BUFFER_SIZE + strlen (current_link_name));

	    sprintf (message, _("Not linked to %s"), current_link_name);
	    report_difference (message);
	    free (message);
	    break;
