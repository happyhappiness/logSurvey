			    {
			      logprintf (LOG_VERBOSE, _("\
Already have correct symlink %s -> %s\n\n"),
					 con->target, escnonprint (f->linkto));
                              dlthis = 0;
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
