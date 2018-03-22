	incremental_version = 0;

      if (incremental_version > TAR_INCREMENTAL_VERSION)
	ERROR((1, 0, _("Unsupported incremental format version: %s"),
	       incremental_version));
      
      t = u = (errno = 0, strtoumax (buf, &ebuf, 10));
