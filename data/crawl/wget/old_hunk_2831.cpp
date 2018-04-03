                 values. Assumme sizes being equal for servers that lie
                 about file size.  */
              cor_val = (con->rs == ST_UNIX || con->rs == ST_WINNT);
              eq_size = cor_val ? (local_size == f->size) : 1 ;
	      if (f->tstamp <= tml && eq_size)
		{
		  /* Remote file is older, file sizes can be compared and
                     are both equal. */
                  logprintf (LOG_VERBOSE, _("\
Remote file no newer than local file `%s' -- not retrieving.\n"), con->target);
		  dlthis = 0;
		}
	      else if (eq_size)
                {
