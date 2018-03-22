	    {
	      buflen = len + NAMLEN (entry);
	      namebuf = xrealloc (namebuf, buflen + 1);
#if 0
	      namebuf[len] = '\0';
	      ERROR ((0, 0, _("File name %s%s too long"),
		      namebuf, entry->d_name));
	      continue;
#endif
	    }
	  strcpy (namebuf + len, entry->d_name);
	  if (!excluded_name (namebuf))
