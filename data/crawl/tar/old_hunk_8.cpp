	  if (expect != 'T')
	    {
	      ERROR ((0, 0,
		      _("Malformed dumpdir: 'T' not preceeded by 'R'")));
	      return false;
	    }
	  if (p[1] == 0 && !has_tempdir)
