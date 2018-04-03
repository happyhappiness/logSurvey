       unrecoverably absent.  */

    static time_t now;
    if (mtime > now && ! file->updated)
      {
	/* This file's time appears to be in the future.
	   Update our concept of the present, and compare again.  */
	extern time_t time ();
	if (mtime > time (&now))
	  {
	    error ("*** File `%s' has modification time in the future",
		   file->name);
