	  quotearg_buffer (buf, sizeof buf, where0, lim - where, o);
	  if (!silent)
	    ERROR ((0, 0,
		    _("Archive contains %.*s where numeric %s value expected"),
		    (int) sizeof buf, buf, type));
	}
