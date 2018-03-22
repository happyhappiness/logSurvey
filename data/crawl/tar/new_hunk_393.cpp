	  switch (prev_status)
	    {
	    case HEADER_STILL_UNREAD:
	      ERROR ((0, 0, _("This does not look like a tar archive")));
	      /* Fall through.  */

	    case HEADER_ZERO_BLOCK:
	    case HEADER_SUCCESS:
	      ERROR ((0, 0, _("Skipping to next header")));
	      break;

	    case HEADER_END_OF_FILE:
