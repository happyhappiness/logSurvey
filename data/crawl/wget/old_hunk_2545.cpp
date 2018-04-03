                  /* Sizes do not match */
                  logprintf (LOG_VERBOSE, _("\
The sizes do not match (local %s) -- retrieving.\n\n"),
			     number_to_static_string (local_size));
                }
            }
	}	/* opt.timestamping && f->type == FT_PLAINFILE */
      switch (f->type)
	{
	case FT_SYMLINK:
	  /* If opt.retr_symlinks is defined, we treat symlinks as
	     if they were normal files.  There is currently no way
	     to distinguish whether they might be directories, and
	     follow them.  */
	  if (!opt.retr_symlinks)
	    {
#ifdef HAVE_SYMLINK
	      if (!f->linkto)
		logputs (LOG_NOTQUIET,
			 _("Invalid name of the symlink, skipping.\n"));
	      else
		{
                  struct_stat st;
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
					 con->target, escnonprint (f->linkto));
                              dlthis = false;
			      break;
			    }
			}
		    }
		  logprintf (LOG_VERBOSE, _("Creating symlink %s -> %s\n"),
			     con->target, escnonprint (f->linkto));
		  /* Unlink before creating symlink!  */
		  unlink (con->target);
		  if (symlink (f->linkto, con->target) == -1)
		    logprintf (LOG_NOTQUIET, "symlink: %s\n", strerror (errno));
		  logputs (LOG_VERBOSE, "\n");
		} /* have f->linkto */
#else  /* not HAVE_SYMLINK */
	      logprintf (LOG_NOTQUIET,
			 _("Symlinks not supported, skipping symlink `%s'.\n"),
			 con->target);
#endif /* not HAVE_SYMLINK */
	    }
	  else                /* opt.retr_symlinks */
	    {
	      if (dlthis)
		err = ftp_loop_internal (u, f, con);
	    } /* opt.retr_symlinks */
	  break;
	case FT_DIRECTORY:
	  if (!opt.recursive)
	    logprintf (LOG_NOTQUIET, _("Skipping directory `%s'.\n"),
		       escnonprint (f->name));
	  break;
	case FT_PLAINFILE:
	  /* Call the retrieve loop.  */
	  if (dlthis)
	    err = ftp_loop_internal (u, f, con);
	  break;
	case FT_UNKNOWN:
	  logprintf (LOG_NOTQUIET, _("%s: unknown/unsupported file type.\n"),
		     escnonprint (f->name));
	  break;
	}	/* switch */

      /* Set the time-stamp information to the local file.  Symlinks
	 are not to be stamped because it sets the stamp on the
	 original.  :( */
      if (!(f->type == FT_SYMLINK && !opt.retr_symlinks)
	  && f->tstamp != -1
          && dlthis
	  && file_exists_p (con->target))
	{
	  /* #### This code repeats in http.c and ftp.c.  Move it to a
             function!  */
	  const char *fl = NULL;
	  if (opt.output_document)
	    {
	      if (output_stream_regular)
		fl = opt.output_document;
	    }
	  else
	    fl = con->target;
	  if (fl)
	    touch (fl, f->tstamp);
	}
      else if (f->tstamp == -1)
	logprintf (LOG_NOTQUIET, _("%s: corrupt time-stamp.\n"), con->target);

      if (f->perms && f->type == FT_PLAINFILE && dlthis)
        {
	  if (opt.preserve_perm)
	    chmod (con->target, f->perms);
        }
      else
	DEBUGP (("Unrecognized permissions for %s.\n", con->target));

      xfree (con->target);
      con->target = old_target;
