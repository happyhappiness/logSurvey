					  | (noerror ? RM_DONTCARE : 0)))
		  && ! noerror)
		error (&fileinfo, "%s: %s", name, strerror (errno));
              free(name);
	    }

	  /* Free any space allocated by conditional_line.  */
