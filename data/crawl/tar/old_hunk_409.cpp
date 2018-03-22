	    lim--;
	  quotearg_buffer (buf, sizeof buf, where0, lim - where, o);
	  ERROR ((0, 0,
		  _("Header contains `%.*s' where numeric %s value expected"),
		  (int) sizeof buf, buf, type));
	}

