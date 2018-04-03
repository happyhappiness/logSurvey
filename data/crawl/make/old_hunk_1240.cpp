	     we don't lose on default suffix rules or makefiles.  */
	  if (f != 0 && f->is_target && !f->double_colon)
	    fatal (flocp,
			    "target file `%s' has both : and :: entries",
			    f->name);
	  f = enter_file (name);
	  /* If there was an existing entry and it was a double-colon
	     entry, enter_file will have returned a new one, making it the
