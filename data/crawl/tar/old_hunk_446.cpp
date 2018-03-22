      if (!bufsize)
	{
	  /* We blew it, maybe.  */

	  ERROR ((0, 0, _("Wrote %ld of %ld bytes to file %s"),
		  fullsize - *sizeleft, fullsize, name));
	  break;
	}
      pos = lseek (file, sparsearray[sparse_index++].offset, 0);

      /* If the number of bytes to be written here exceeds the size of
	 the temporary buffer, do it in steps.  */
