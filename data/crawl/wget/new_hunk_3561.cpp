#else  /* not HAVE_SYMLINK */
	      logprintf (LOG_NOTQUIET,
			 _("Symlinks not supported, skipping symlink `%s'.\n"),
			 con->target);
#endif /* not HAVE_SYMLINK */
	    }
	  else                /* opt.retr_symlinks */
