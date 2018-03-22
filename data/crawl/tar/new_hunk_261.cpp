   I'm not sure overall identical sparsity is verified.  */

static void
diff_sparse_files (void)
{
  off_t remaining_size = current_stat_info.stat.st_size;
  char *buffer = xmalloc (BLOCKSIZE * sizeof (char));
  size_t buffer_size = BLOCKSIZE;
  union block *data_block = 0;
  int counter = 0;
  int different = 0;

  if (! fill_in_sparse_array ())
    fatal_exit ();

  while (remaining_size > 0)
    {
      ssize_t status;
      size_t chunk_size;
      off_t offset;

#if 0
      off_t amount_read = 0;
#endif

      data_block = find_next_block ();
      if (!data_block)
	FATAL_ERROR ((0, 0, _("Unexpected EOF in archive")));
      chunk_size = sparsearray[counter].numbytes;
      if (!chunk_size)
	break;

      offset = sparsearray[counter].offset;
      if (lseek (diff_handle, offset, SEEK_SET) < 0)
	{
	  seek_error_details (current_stat_info.file_name, offset);
	  report_difference (0);
	}

      /* Take care to not run out of room in our buffer.  */

      while (buffer_size < chunk_size)
	{
	  if (buffer_size * 2 < buffer_size)
	    xalloc_die ();
	  buffer_size *= 2;
	  buffer = xrealloc (buffer, buffer_size * sizeof (char));
	}

      while (chunk_size > BLOCKSIZE)
	{
	  if (status = safe_read (diff_handle, buffer, BLOCKSIZE),
	      status != BLOCKSIZE)
	    {
	      if (status < 0)
		{
		  read_error (current_stat_info.file_name);
		  report_difference (0);
		}
	      else
		{
		  char message[MESSAGE_BUFFER_SIZE];

		  sprintf (message, _("Could only read %lu of %lu bytes"),
			   (unsigned long) status, (unsigned long) chunk_size);
		  report_difference (message);
		}
	      break;
