	     && (dig = base64_map[(unsigned char) *where]) < 64)
	{
	  if (value << LG_64 >> LG_64 != value)
	    goto out_of_range;
	  value = (value << LG_64) | dig;
	  where++;
	}
