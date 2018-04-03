	      ndot = 0;
	    }
	}
      logprintf (LOG_VERBOSE, "\n%5ldK ->", nrow * line_bytes / 1024);
    }
  /* Offset gets incremented by current value.  */
  offs += res;
