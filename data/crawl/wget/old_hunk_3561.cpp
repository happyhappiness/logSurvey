#else  /* not HAVE_SYMLINK */
	      logprintf (LOG_NOTQUIET,
			 _("Symlinks not supported, skipping symlink `%s'.\n"),
			 u->local);
#endif /* not HAVE_SYMLINK */
	    }
	  else                /* opt.retr_symlinks */
