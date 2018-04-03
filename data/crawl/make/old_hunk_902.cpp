#ifndef NO_ARCHIVES
  if (ar_name (file->name))
    {
      if (ar_member_date (file->name) != FILE_TIMESTAMP_S (file->last_mtime))
	{
	  if (on_behalf_of)
	    error (NILF, _("*** [%s] Archive member `%s' may be bogus; not deleted"),
