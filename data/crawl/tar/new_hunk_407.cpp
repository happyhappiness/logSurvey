      do
	{
	  if (value << LG_8 >> LG_8 != value)
	    {
	      ERROR ((0, 0,
		      _("Archive octal string `%.*s' is out of %s range"),
		      (int) digs, where0, type));
	      return -1;
	    }
	  value = (value << LG_8) | (*where++ - '0');
	}
      while (where != lim && ISODIGIT (*where));
