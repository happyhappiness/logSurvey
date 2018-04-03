	  else
#endif
	    pid = wait (&status);

	  if (pid <= 0)
	    /* No local children.  */
