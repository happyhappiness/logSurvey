    {
      if (has_insecure_name_p (f->name))
	{
	  logprintf (LOG_VERBOSE, _("Rejecting `%s'.\n"),
		     escnonprint (f->name));
	  f = delelement (f, &start);
	}
      else
