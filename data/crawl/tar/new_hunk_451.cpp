
	    if (count == bufsize)
	      continue;
	    else
	      {
		char buf[UINTMAX_STRSIZE_BOUND];
		ERROR ((0, 0,
			_("File %s shrunk by %s bytes, padding with zeros"),
			p, STRINGIFY_BIGINT (sizeleft, buf)));
		goto padit;		/* short read */
	      }
	  }

      if (multi_volume_option)
