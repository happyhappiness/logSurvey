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
