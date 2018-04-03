	      free ((char *)files);
	      files = next;

              r = read_makefile (name, (RM_INCLUDED | RM_NO_TILDE
                                        | (noerror ? RM_DONTCARE : 0)));
	      if (!r)
                {
                  if (!noerror)
                    error (&fileinfo, "%s: %s", name, strerror (errno));
                  free (name);
                }
	    }
