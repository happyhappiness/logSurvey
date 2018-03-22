
      if (overflow)
	{
	  if (type)
	    ERROR ((0, 0,
		    _("Archive octal value %.*s is out of %s range"),
		    (int) (where - where1), where1, type));
	  return -1;
	}
    }
  else if (*where == '-' || *where == '+')
    {
      /* Parse base-64 output produced only by tar test versions
	 1.13.6 (1999-08-11) through 1.13.11 (1999-08-23).
	 Support for this will be withdrawn in future releases.  */
      int dig;
      static int warned_once;
      if (! warned_once)
	{
	  warned_once = 1;
	  WARN ((0, 0,
		 _("Archive contains obsolescent base-64 headers")));
	}
      negative = *where++ == '-';
      while (where != lim
	     && (dig = base64_map[(unsigned char) *where]) < 64)
	{
	  if (value << LG_64 >> LG_64 != value)
	    {
	      char *string = alloca (digs + 1);
	      memcpy (string, where0, digs);
	      string[digs] = '\0';
	      if (type)
		ERROR ((0, 0,
			_("Archive signed base-64 string %s is out of %s range"),
			quote (string), type));
	      return -1;
	    }
	  value = (value << LG_64) | dig;
	  where++;
	}
    }
  else if (*where == '\200' /* positive base-256 */
	   || *where == '\377' /* negative base-256 */)
    {
      /* Parse base-256 output.  A nonnegative number N is
	 represented as (256**DIGS)/2 + N; a negative number -N is
	 represented as (256**DIGS) - N, i.e. as two's complement.
	 The representation guarantees that the leading bit is
	 always on, so that we don't confuse this format with the
	 others (assuming ASCII bytes of 8 bits or more).  */
      int signbit = *where & (1 << (LG_256 - 2));
      uintmax_t topbits = (((uintmax_t) - signbit)
			   << (CHAR_BIT * sizeof (uintmax_t)
			       - LG_256 - (LG_256 - 2)));
      value = (*where++ & ((1 << (LG_256 - 2)) - 1)) - signbit;
      for (;;)
	{
	  value = (value << LG_256) + (unsigned char) *where++;
	  if (where == lim)
	    break;
	  if (((value << LG_256 >> LG_256) | topbits) != value)
	    {
	      if (type)
		ERROR ((0, 0,
			_("Archive base-256 value is out of %s range"),
			type));
	      return -1;
	    }
	}
      negative = signbit;
      if (negative)
	value = -value;
    }

  if (where != lim && *where && !ISSPACE ((unsigned char) *where))
