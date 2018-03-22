	{
	  count = full_write (fd, data_block->buffer, BLOCKSIZE);
	  if (count < 0)
	    write_error (name);
	  written -= count;
	  *sizeleft -= count;
	  set_next_block_after (data_block);
