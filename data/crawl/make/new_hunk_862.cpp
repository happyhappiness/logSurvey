	      free ((char *)files);
	      files = next;

              r = eval_makefile (name, (RM_INCLUDED | RM_NO_TILDE
                                        | (noerror ? RM_DONTCARE : 0)));
	      if (!r)
                {
                  if (!noerror)
                    error (fstart, "%s: %s", name, strerror (errno));
                  free (name);
                }
	    }
