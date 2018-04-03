      else
	{
	  /* This is a dependency file we cannot remake.  Fail.  */
	  static char noway[] = "No rule to make target";
	  if (keep_going_flag || file->dontcare)
	    {
	      if (!file->dontcare)
		error ("*** %s `%s'.", noway, file->name);
 	      file->update_status = 1;
	    }
	  else
