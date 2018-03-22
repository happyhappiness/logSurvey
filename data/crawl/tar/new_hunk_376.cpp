
		if (remove_files_option)
		  if (unlink (p) == -1)
		    unlink_error (p);

		/* We dumped it.  */
		return;
