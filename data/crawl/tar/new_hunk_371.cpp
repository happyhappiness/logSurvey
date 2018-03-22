
	  ERROR ((0, 0, _("Wrote %s of %s bytes to file %s"),
		  STRINGIFY_BIGINT (fullsize - *sizeleft, buf1),
		  STRINGIFY_BIGINT (fullsize, buf2), quote (name)));
	  break;
	}

      if (lseek (file, sparsearray[sparse_index++].offset, SEEK_SET) < 0)
	{
	  char buf[UINTMAX_STRSIZE_BOUND];
	  int e = errno;
	  ERROR ((0, e, _("lseek error at byte %s in file %s"),
		  STRINGIFY_BIGINT (sparsearray[sparse_index - 1].offset,
				    buf),
		  quote (name)));
	  break;
	}

