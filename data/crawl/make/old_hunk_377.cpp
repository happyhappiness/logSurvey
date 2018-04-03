
      /* Expand the pattern using LIB as a replacement.  */
      {
	char c = p[len];
	char *p3, *p4;

	p[len] = '\0';
	p3 = find_percent (p);
	if (!p3)
	  {
	    /* Give a warning if there is no pattern.  */
	    error (NILF, _(".LIBPATTERNS element '%s' is not a pattern"), p);
            p[len] = c;
	    continue;
	  }
	p4 = variable_buffer_output (libbuf, p, p3-p);
	p4 = variable_buffer_output (p4, lib, liblen);
	p4 = variable_buffer_output (p4, p3+1, len - (p3-p));
	p[len] = c;
      }

      /* Look first for 'libNAME.a' in the current directory.  */
      mtime = name_mtime (libbuf);
      if (mtime != NONEXISTENT_MTIME)
	{
	  if (mtime_ptr != 0)
	    *mtime_ptr = mtime;
	  file = strcache_add (libbuf);
          /* This by definition will have the best index, so stop now.  */
          break;
	}

      /* Now try VPATH search on that.  */

