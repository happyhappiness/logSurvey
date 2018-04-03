                                         | (noerror ? RM_DONTCARE : 0)));
 	      if (!r && !noerror)
                 error (fstart, "%s: %s", name, strerror (errno));
-              free (name);
 	    }
 
 	  /* Restore conditional state.  */
