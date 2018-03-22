	    /* Error in writing to file.  Print it, skip to next file in
	       archive.  */

	    write_error_details (CURRENT_FILE_NAME, sstatus, written);
	    skip_file (size - written);
	    break;		/* still do the close, mod time, chmod, etc */
	  }
