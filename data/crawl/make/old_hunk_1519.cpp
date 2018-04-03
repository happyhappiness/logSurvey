      return o;
    }

  while ((p = sindex (t, 0, subst, slen)) != 0)
    {
      /* Output everything before this occurrence of the string to replace.  */
      if (p > t)
	o = variable_buffer_output (o, t, p - t);
