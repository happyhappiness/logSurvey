	  data_block = find_next_block ();
	}

      count = write (fd, data_block->buffer, (size_t) written);

      if (count < 0)
	ERROR ((0, errno, _("%s: Could not write to file"), name));
      else if (count != written)
	{
	  ERROR ((0, 0, _("%s: Could only write %d of %d bytes"),
		     name, count, totalsize));
	  skip_file ((long) (*sizeleft));
	}

      written -= count;
