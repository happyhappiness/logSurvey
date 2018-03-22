	  *sizeleft -= count;
	  set_next_block_after (data_block);
	  data_block = find_next_block ();
	}

      count = full_write (fd, data_block->buffer, written);
