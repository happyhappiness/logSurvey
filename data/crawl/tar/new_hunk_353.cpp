
      if (deref_stat (dereference_option, name->name, &statbuf) != 0)
	{
	  stat_error (name->name);
	  continue;
	}
      if (S_ISDIR (statbuf.st_mode))
