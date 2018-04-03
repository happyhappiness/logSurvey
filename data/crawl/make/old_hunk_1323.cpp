	     whose commands were preinitialized.  */
	  else if (cmds != 0 && f->cmds != 0 && f->is_target)
	    {
	      makefile_error (cmds->filename, cmds->lineno,
			      "warning: overriding commands for target `%s'",
			      f->name);
	      makefile_error (f->cmds->filename, f->cmds->lineno,
			      "warning: ignoring old commands for target `%s'",
			      f->name);
	    }
