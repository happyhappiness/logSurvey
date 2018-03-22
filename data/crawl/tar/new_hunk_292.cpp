  typeflag = current_header->header.typeflag;
  switch (typeflag)
    {
    case GNUTYPE_SPARSE:
      file_size = OFF_FROM_HEADER (current_header->oldgnu_header.realsize);
      if (! fill_in_sparse_array ())
	return;
      /* Fall through.  */

    case AREGTYPE:
