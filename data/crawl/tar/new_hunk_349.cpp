	  if (!o)
	    {
	      o = clone_quoting_options (0);
	      set_quoting_style (o, locale_quoting_style);
	    }

	  while (where0 != lim && ! lim[-1])
	    lim--;
	  quotearg_buffer (buf, sizeof buf, where0, lim - where, o);
	  ERROR ((0, 0,
		  _("Archive contains %.*s where numeric %s value expected"),
		  (int) sizeof buf, buf, type));
	}

