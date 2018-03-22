   I'm not sure overall identical sparsity is verified.  */

static void
diff_sparse_files (int size_of_file)
{
  int remaining_size = size_of_file;
  char *buffer = (char *) xmalloc (BLOCKSIZE * sizeof (char));
  int buffer_size = BLOCKSIZE;
  union block *data_block = NULL;
  int counter = 0;
  int different = 0;

  fill_in_sparse_array ();

  while (remaining_size > 0)
    {
      int status;
      long chunk_size;
#if 0
      int amount_read = 0;
#endif

      data_block = find_next_block ();
      chunk_size = sparsearray[counter].numbytes;
      if (!chunk_size)
	break;

      lseek (diff_handle, sparsearray[counter].offset, 0);

      /* Take care to not run out of room in our buffer.  */

      while (buffer_size < chunk_size)
	{
	  buffer_size *= 2;
	  buffer = (char *) xrealloc (buffer, buffer_size * sizeof (char));
	}

      while (chunk_size > BLOCKSIZE)
	{
	  if (status = read (diff_handle, buffer, BLOCKSIZE),
	      status != BLOCKSIZE)
	    {
	      if (status < 0)
		{
		  WARN ((0, errno, _("Cannot read %s"), current_file_name));
		  report_difference (NULL);
		}
	      else
		{
		  char message[MESSAGE_BUFFER_SIZE];

		  sprintf (message, _("Could only read %d of %ld bytes"),
			   status, chunk_size);
		  report_difference (message);
		}
	      break;
