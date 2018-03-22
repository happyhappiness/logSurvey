	  if ((int) NAMLEN (entry) + len >= buflen)
	    {
	      buflen = len + NAMLEN (entry);
	      namebuf = (char *) xrealloc (namebuf, buflen + 1);
#if 0
	      namebuf[len] = '\0';
	      ERROR ((0, 0, _("File name %s%s too long"),
