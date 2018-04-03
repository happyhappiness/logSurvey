      fprintf (fp, "  ");
      if (f->tstamp != -1)
	{
	  /* #### Should we translate the months? */
	  static char *months[] = {
	    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
	    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
