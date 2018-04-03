		 tms, tmrate, locf, len);
      logprintf (LOG_NONVERBOSE, "%s URL: %s [%ld] -> \"%s\" [%d]\n",
		 tms, u->url, len, locf, count);
      /* Do not count listings among the downloaded stuff, since they
	 will get deleted anyway.  */
      if (!(con->cmd & DO_LIST))
	{
	  ++opt.numurls;
	  opt.downloaded += len;
	}
      /* Restore the original leave-pendingness.  */
      if (orig_lp)
	con->cmd |= LEAVE_PENDING;
