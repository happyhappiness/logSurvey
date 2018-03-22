
      if (deref_stat (dereference_option, name->name, &statbuf) != 0)
	{
	  ERROR ((0, errno, _("Cannot stat %s"), name->name));
	  continue;
	}
      if (S_ISDIR (statbuf.st_mode))
