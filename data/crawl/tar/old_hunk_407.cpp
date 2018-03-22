      do
	{
	  if (value << LG_8 >> LG_8 != value)
	    goto out_of_range;
	  value = (value << LG_8) | (*where++ - '0');
	}
      while (where != lim && ISODIGIT (*where));
