              free_dep_chain (f->deps);
	      f->deps = 0;
	    }
	}
      else
	{
	  /* Double-colon.  Make a new record even if there already is one.  */
	  f = lookup_file (name);

	  /* Check for both : and :: rules.  Check is_target so we don't lose
	     on default suffix rules or makefiles.  */
	  if (f != 0 && f->is_target && !f->double_colon)
	    fatal (flocp,
                   _("target file `%s' has both : and :: entries"), f->name);

	  f = enter_file (strcache_add (name));
	  /* If there was an existing entry and it was a double-colon entry,
	     enter_file will have returned a new one, making it the prev
