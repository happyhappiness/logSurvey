#ifndef NO_ARCHIVES
  if (ar_name (file->name))
    {
      time_t file_date = (file->last_mtime == NONEXISTENT_MTIME
			  ? (time_t) -1
			  : (time_t) FILE_TIMESTAMP_S (file->last_mtime));
      if (ar_member_date (file->name) != file_date)
	{
	  if (on_behalf_of)
	    error (NILF, _("*** [%s] Archive member `%s' may be bogus; not deleted"),
