	{
	  if (type && !silent)
	    ERROR ((0, 0,
		    /* TRANSLATORS: %s is type of the value (gid_t, uid_t, etc.) */
		    _("Blanks in header where numeric %s value expected"),
		    type));
	  return -1;
