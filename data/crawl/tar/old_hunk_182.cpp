
	  if (!overflow && value <= minus_minval)
	    {
	      WARN ((0, 0,
		     _("Archive octal value %.*s is out of %s range; assuming two's complement"),
		     (int) (where - where1), where1, type));
	      negative = 1;
	    }
	}

      if (overflow)
	{
	  if (type)
	    ERROR ((0, 0,
		    _("Archive octal value %.*s is out of %s range"),
		    (int) (where - where1), where1, type));
