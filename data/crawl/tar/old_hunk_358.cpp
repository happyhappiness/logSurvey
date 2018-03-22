	{
	  count = full_write (fd, data_block->buffer, BLOCKSIZE);
	  if (count < 0)
	    ERROR ((0, errno, _("%s: Could not write to file"), name));
	  written -= count;
	  *sizeleft -= count;
	  set_next_block_after (data_block);
