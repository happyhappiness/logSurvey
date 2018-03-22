	  unquote_string (name_end + 4);
	  if (symlink (name, name_end + 4)
	      && (unlink (name_end + 4) || symlink (name, name_end + 4)))
	    ERROR ((0, errno, _("Cannot symlink %s to %s"),
		    name, name_end + 4));
	  else if (verbose_option)
	    WARN ((0, 0, _("Symlinked %s to %s"), name, name_end + 4));
	}
