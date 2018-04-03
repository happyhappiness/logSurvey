	  else
#endif
	    pid = wait (&status);

	  if (pid < 0)
	    pfatal_with_name ("wait");
	  else if (pid == 0)
	    /* No local children.  */
	    break;
	  else
