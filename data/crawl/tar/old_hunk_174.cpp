	{
	  if (type && !silent)
	    ERROR ((0, 0,
		    _("Archive octal value %.*s is out of %s range"),
		    (int) (where - where1), where1, type));
	  return -1;
