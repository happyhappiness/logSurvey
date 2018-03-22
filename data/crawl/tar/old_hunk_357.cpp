      if (lseek (fd, sparsearray[sparse_ind].offset, SEEK_SET) < 0)
	{
	  char buf[UINTMAX_STRSIZE_BOUND];
	  ERROR ((0, errno, _("%s: lseek error at byte %s"),
		  STRINGIFY_BIGINT (sparsearray[sparse_ind].offset, buf),
		  name));
	  return;
	}
      written = sparsearray[sparse_ind++].numbytes;
