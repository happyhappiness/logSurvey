      saved_append (write_ptr);
      fputs (write_ptr, logfp);
      if (bigmsg)
	xfree (bigmsg);
    }
  if (!opt.no_flush)
    fflush (logfp);
