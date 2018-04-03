	  if (*p == '\0')
	    {
	      error (&fileinfo,
			      _("no file name for `%sinclude'"),
			      noerror ? "-" : "");
	      continue;
	    }

