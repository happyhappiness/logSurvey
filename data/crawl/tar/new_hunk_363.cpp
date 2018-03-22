	       archive.  */

	    if (sstatus < 0)
	      write_error (CURRENT_FILE_NAME);
	    else
	      ERROR ((0, 0, _("%s: Could only write %lu of %lu bytes"),
		      quotearg_colon (CURRENT_FILE_NAME),
		      (unsigned long) sstatus,
		      (unsigned long) written));
	    skip_file (size - written);
