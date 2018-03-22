	    break;
	  if (((value << LG_256 >> LG_256) | topbits) != value)
	    {
	      if (type)
		ERROR ((0, 0,
			_("Archive base-256 value is out of %s range"),
			type));
