	     on default suffix rules or makefiles.  */
	  if (f != 0 && f->is_target && !f->double_colon)
	    fatal (flocp,
                   _("target file `%s' has both : and :: entries"), f->name);

	  f = enter_file (strcache_add (name));
	  /* If there was an existing entry and it was a double-colon entry,
