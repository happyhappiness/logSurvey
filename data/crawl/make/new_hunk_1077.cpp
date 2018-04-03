      if (ar_member_date (file->name) != FILE_TIMESTAMP_S (file->last_mtime))
	{
	  if (on_behalf_of)
	    error (NILF, _("*** [%s] Archive member `%s' may be bogus; not deleted"),
		   on_behalf_of, file->name);
	  else
	    error (NILF, _("*** Archive member `%s' may be bogus; not deleted"),
		   file->name);
	}
      return;
