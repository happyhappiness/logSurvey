      while (maximum)
	{
	  count = maximum < BLOCKSIZE ? maximum : BLOCKSIZE;
	  if (full_write (STDOUT_FILENO, cursor, count) != count)
	    write_error (use_compress_program_option);
	  cursor += count;
	  maximum -= count;
	}
