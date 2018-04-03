	      if (! read_makefile (name, (RM_INCLUDED | RM_NO_TILDE
					  | (noerror ? RM_DONTCARE : 0)))
		  && ! noerror)
		error (&fileinfo, "%s: %s", name, strerror (errno));
              free(name);
	    }

