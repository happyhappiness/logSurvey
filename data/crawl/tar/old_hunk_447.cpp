	  count = read (file, start->buffer, BLOCKSIZE);
	  if (count < 0)
	    {
	      ERROR ((0, errno, _("\
Read error at byte %ld, reading %d bytes, in file %s"),
			 fullsize - *sizeleft, bufsize, name));
	      return 1;
	    }
	  bufsize -= count;
	  *sizeleft -= count;
	  set_next_block_after (start);
	  nwritten += BLOCKSIZE;	/* FIXME: ??? */
	  start = find_next_block ();
	  memset (start->buffer, 0, BLOCKSIZE);
	}
