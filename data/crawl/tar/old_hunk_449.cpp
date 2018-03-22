	  if (count != bufsize)
	    {
	      ERROR ((0, 0,
		      _("File %s shrunk by %d bytes, padding with zeros"),
		      name, sizeleft));
	      return 1;
	    }
	  start = find_next_block ();
