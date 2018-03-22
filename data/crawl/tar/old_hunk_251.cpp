	  while (status == HEADER_FAILURE);

	  ERROR ((0, 0,
		  _("VERIFY FAILURE: %d invalid header(s) detected"), counter));
	}
      if (status == HEADER_ZERO_BLOCK || status == HEADER_END_OF_FILE)
	break;
