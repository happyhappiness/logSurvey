
  if (digs != 0 && *where && !ISSPACE (*where))
    {
      if (type)
	{
	  char buf[1000]; /* Big enough to represent any header.  */
	  static struct quoting_options *o;

	  if (!o)
	    {
	      o = clone_quoting_options ((struct quoting_options *) 0);
	      set_quoting_style (o, escape_quoting_style);
	    }

	  quotearg_buffer (buf, sizeof buf, where0, digs0, o);
	  ERROR ((0, 0,
		  _("Header contains \"%.*s\" where octal %s value expected"),
		  (int) sizeof buf, buf, type));
	}

      return -1;
    }

