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
      while (written > BLOCKSIZE)
	{
	  count = full_write (fd, data_block->buffer, BLOCKSIZE);
	  written -= count;
	  *sizeleft -= count;
	  if (count != BLOCKSIZE)
	    {
	      write_error_details (name, count, BLOCKSIZE);
	      return;
	    }
	  set_next_block_after (data_block);
	  data_block = find_next_block ();
	  if (! data_block)
	    {
	      ERROR ((0, 0, _("Unexpected EOF in archive")));
	      return;
	    }
	}

      count = full_write (fd, data_block->buffer, written);
      *sizeleft -= count;

      if (count != written)
	{
	  write_error_details (name, count, written);
	  return;
	}

      set_next_block_after (data_block);
    }
}

/* Fix the statuses of all directories whose statuses need fixing, and
