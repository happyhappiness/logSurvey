      union block *data_block = find_next_block ();
      if (! data_block)
	{
	  ERROR ((0, 0, _("Unexpected EOF in archive")));
	  return;
	}
      if (lseek (fd, sparsearray[sparse_ind].offset, SEEK_SET) < 0)
	{
	  seek_error_details (name, sparsearray[sparse_ind].offset);
	  return;
	}
      written = sparsearray[sparse_ind++].numbytes;
