	  ERROR ((0, 0, _("%s: Required occurrence not found in archive"),
		  quotearg_colon (cursor->name)));
      }

  /* Don't bother freeing the name list; we're about to exit.  */
  namelist = 0;
  nametail = &namelist;
