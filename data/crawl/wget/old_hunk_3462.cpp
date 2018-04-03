
      if (!link_has_scheme)
	{
	  /* We have no base, and the link does not have a host
	     attached to it.  Nothing we can do.  */
	  /* #### Should we print a warning here?  Wget 1.5.x used to.  */
	  return NULL;
	}

