	    {
	      struct nameseq *next = files->next;
	      char *name = files->name;
	      free ((char *)files);
	      files = next;

	      if (! read_makefile (name, (RM_INCLUDED | RM_NO_TILDE
					  | (noerror ? RM_DONTCARE : 0)))
		  && ! noerror)
		error (&fileinfo, "%s: %s", name, strerror (errno));

              /* We can't free NAME here, in case some of the commands,
                 etc. still contain references to the filename.  */
	    }

	  /* Free any space allocated by conditional_line.  */
