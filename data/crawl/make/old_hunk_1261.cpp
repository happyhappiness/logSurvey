      merge_variable_set_lists (&oldfile->variables, file->variables);

      if (oldfile->double_colon && file->is_target && !file->double_colon)
	fatal ("can't rename single-colon `%s' to double-colon `%s'",
	       oldname, name);
      if (!oldfile->double_colon  && file->double_colon)
	{
	  if (oldfile->is_target)
	    fatal ("can't rename double-colon `%s' to single-colon `%s'",
		   oldname, name);
	  else
	    oldfile->double_colon = file->double_colon;
