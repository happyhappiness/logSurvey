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
