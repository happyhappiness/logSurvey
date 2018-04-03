                                        | (noerror ? RM_DONTCARE : 0)));
	      if (!r && !noerror)
                error (fstart, "%s: %s", name, strerror (errno));
	    }

	  /* Restore conditional state.  */
