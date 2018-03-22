	    {
	      buflen = len + NAMLEN (entry);
	      namebuf = xrealloc (namebuf, buflen + 1);
	    }
	  strcpy (namebuf + len, entry->d_name);
	  if (!excluded_name (namebuf))
