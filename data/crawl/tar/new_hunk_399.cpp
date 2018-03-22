  value = 0;
  if (ISODIGIT (*where))
    {
      char const *where1 = where;
      uintmax_t overflow = 0;

      for (;;)
	{
	  value += *where++ - '0';
	  if (where == lim || ! ISODIGIT (*where))
	    break;
	  overflow |= value ^ (value << LG_8 >> LG_8);
	  value <<= LG_8;
	}

      /* Parse the output of older, unportable tars, which generate
	 negative values in two's complement octal.  */
      if ((overflow || maxval < value) && '4' <= *where1)
	{
	  /* Compute the negative of the input value, assuming two's
	     complement.  */
	  for (value = 0, where = where1, overflow = 0; ; )
	    {
	      value += 7 - (*where++ - '0');
	      if (where == lim || ! ISODIGIT (*where))
		break;
	      overflow |= value ^ (value << LG_8 >> LG_8);
	      value <<= LG_8;
	    }
	  value++;
	  overflow |= !value;

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
	  ERROR ((0, 0,
		  _("Archive octal value %.*s is out of %s range"),
		  (int) (where - where1), where1, type));
	  return -1;
	}
    }
  else if (type)
    {
      /* The following forms cannot appear as checksums, so we don't
	 check for them if TYPE is null.  */

      if (*where == '-' || *where == '+')
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
		  ERROR ((0, 0,
			  _("Archive signed base-64 string `%.*s' is out of %s range"),
			  (int) digs, where0, type));
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
    }

