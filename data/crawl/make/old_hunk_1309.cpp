	      if (! read_makefile (name, (RM_INCLUDED | RM_NO_TILDE
					  | (noerror ? RM_DONTCARE : 0)))
		  && ! noerror)
		makefile_error (filename, lineno,
				"%s: %s", name, strerror (errno));
              free(name);
	    }
