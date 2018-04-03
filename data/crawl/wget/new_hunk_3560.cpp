                  struct stat st;
		  /* Check whether we already have the correct
                     symbolic link.  */
                  int rc = lstat (con->target, &st);
                  if (rc == 0)
		    {
		      size_t len = strlen (f->linkto) + 1;
		      if (S_ISLNK (st.st_mode))
			{
			  char *link_target = (char *)alloca (len);
			  size_t n = readlink (con->target, link_target, len);
			  if ((n == len - 1)
			      && (memcmp (link_target, f->linkto, n) == 0))
			    {
			      logprintf (LOG_VERBOSE, _("\
Already have correct symlink %s -> %s\n\n"),
					 con->target, f->linkto);
                              dlthis = 0;
			      break;
			    }
			}
		    }
		  logprintf (LOG_VERBOSE, _("Creating symlink %s -> %s\n"),
			     con->target, f->linkto);
		  /* Unlink before creating symlink!  */
		  unlink (con->target);
		  if (symlink (f->linkto, con->target) == -1)
		    logprintf (LOG_NOTQUIET, "symlink: %s\n",
			       strerror (errno));
		  logputs (LOG_VERBOSE, "\n");
