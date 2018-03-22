  flush_read ();
  while (1)
    {
      enum read_header status = read_header ();

      if (status == HEADER_FAILURE)
	{
	  int counter = 0;

	  while (status == HEADER_FAILURE);
	    {
	      counter++;
	      status = read_header ();
	    }
	  ERROR ((0, 0,
		  _("VERIFY FAILURE: %d invalid header(s) detected"), counter));
	}
