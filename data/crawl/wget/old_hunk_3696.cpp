      if (f->type != FT_DIRECTORY)
	continue;
      odir = u->dir;
      len = 1 + strlen (u->dir) + 1 + strlen (f->name) + 1;
      /* Allocate u->dir off stack, but reallocate only if a larger
         string is needed.  */
      if (len > current_length)
	current_container = (char *)alloca (len);
      u->dir = current_container;
      sprintf (u->dir, "/%s%s%s", odir + (*odir == '/'),
	      (!*odir || (*odir == '/' && !* (odir + 1))) ? "" : "/", f->name);
      if (!accdir (u->dir, ALLABS))
	{
	  logprintf (LOG_VERBOSE, _("\
