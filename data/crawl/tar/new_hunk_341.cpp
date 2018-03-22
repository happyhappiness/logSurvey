	      exhdr = find_next_block ();
	      if (! exhdr)
		{
		  ERROR ((0, 0, _("Unexpected EOF in archive")));
		  return;
		}
	      for (counter = 0; counter < SPARSES_IN_SPARSE_HEADER; counter++)
