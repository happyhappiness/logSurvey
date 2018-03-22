	    if (written > size)
	      written = size;
	    errno = 0;		/* FIXME: errno should be read-only */
	    status = write (fd, data_block->buffer, (size_t) written);

	    set_next_block_after ((union block *)
				  (data_block->buffer + written - 1));
	    if (status == written)
	      continue;

	    /* Error in writing to file.  Print it, skip to next file in
	       archive.  */

	    if (status < 0)
	      ERROR ((0, errno, _("%s: Could not write to file"),
		      CURRENT_FILE_NAME));
	    else
	      ERROR ((0, 0, _("%s: Could only write %d of %d bytes"),
		      CURRENT_FILE_NAME, status, written));
	    skip_file ((long) (size - written));
	    break;		/* still do the close, mod time, chmod, etc */
	  }

