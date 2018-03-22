      count = full_write (fd, data_block->buffer, written);

      if (count < 0)
	write_error (name);
      else if (count != written)
	{
	  char buf1[UINTMAX_STRSIZE_BOUND];
	  char buf2[UINTMAX_STRSIZE_BOUND];
	  ERROR ((0, 0, _("%s: Could only write %s of %s bytes"),
		  quotearg_colon (name),
		  STRINGIFY_BIGINT (totalsize - *sizeleft, buf1),
		  STRINGIFY_BIGINT (totalsize, buf2)));
	  skip_file (*sizeleft);
