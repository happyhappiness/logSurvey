      while (maximum)
	{
	  count = maximum < BLOCKSIZE ? maximum : BLOCKSIZE;
	  status = full_write (STDOUT_FILENO, cursor, count);
	  if (status < 0)
	    write_error (use_compress_program_option);

	  if (status != count)
	    {
	      ERROR ((0, 0, _("Write to compression program short %lu bytes"),
		      (unsigned long) (count - status)));
	      count = status;
	    }

	  cursor += count;
	  maximum -= count;
	}
