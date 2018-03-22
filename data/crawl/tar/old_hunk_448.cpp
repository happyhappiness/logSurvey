	char buffer[BLOCKSIZE];

	clear_buffer (buffer);
	count = read (file, buffer, (size_t) bufsize);
	memcpy (start->buffer, buffer, BLOCKSIZE);
      }

      if (count < 0)
	{
	  ERROR ((0, errno,
		  _("Read error at byte %ld, reading %d bytes, in file %s"),
		  fullsize - *sizeleft, bufsize, name));
	  return 1;
	}
#if 0
