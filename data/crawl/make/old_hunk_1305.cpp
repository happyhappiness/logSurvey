	  if (in_ignored_define)
	    in_ignored_define = 0;
	  else
	    makefile_fatal (filename, lineno, "extraneous `endef'");
	  continue;
	}

