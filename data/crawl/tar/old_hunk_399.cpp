  value = 0;
  if (ISODIGIT (*where))
    {
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

      /* Parse the output of older tars, which output negative values
	 in two's complement octal.  This method works only if the
	 type has the same number of bits as it did on the host that
	 created the tar file, but that's the best we can do.  */
      if (maxval < value && value - maxval <= minus_minval)
	{
	  value = minus_minval - (value - maxval);
	  negative = 1;
	}
    }
  else if (*where == '-' || *where == '+')
    {
      int dig;
      negative = *where++ == '-';
      while (where != lim
	     && (dig = base64_map[(unsigned char) *where]) < 64)
	{
	  if (value << LG_64 >> LG_64 != value)
	    {
	      ERROR ((0, 0,
		      _("Archive signed base 64 string `%.*s' is out of %s range"),
		      (int) digs, where0, type));
	      return -1;
	    }
	  value = (value << LG_64) | dig;
	  where++;
	}
    }

