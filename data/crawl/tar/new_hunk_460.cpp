	    if (written > size)
	      written = size;
	    errno = 0;		/* FIXME: errno should be read-only */
	    sstatus = write (fd, data_block->buffer, written);

	    set_next_block_after ((union block *)
				  (data_block->buffer + written - 1));
	    if (sstatus == written)
	      continue;

	    /* Error in writing to file.  Print it, skip to next file in
	       archive.  */

	    if (sstatus < 0)
	      ERROR ((0, errno, _("%s: Could not write to file"),
		      CURRENT_FILE_NAME));
	    else
	      ERROR ((0, 0, _("%s: Could only write %lu of %lu bytes"),
		      CURRENT_FILE_NAME,
		      (unsigned long) sstatus,
		      (unsigned long) written));
	    skip_file (size - written);
	    break;		/* still do the close, mod time, chmod, etc */
	  }

