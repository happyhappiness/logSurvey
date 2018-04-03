	     .orig suffix. */
	  if (!stat (u->local, &st))
	    {
	      /* Else, get it from the file.  */
	      local_size = st.st_size;
	      tml = st.st_mtime;
	      if (local_size == f->size && tml >= f->tstamp)
		{
		  logprintf (LOG_VERBOSE, _("\
Server file no newer than local file `%s' -- not retrieving.\n\n"), u->local);
		  dlthis = 0;
		}
	      else if (local_size != f->size)
		{
		  if (host_type == ST_VMS)
		    {
		      logprintf (LOG_VERBOSE, _("\
Cannot compare sizes, remote system is VMS.\n"));
		      dlthis = 0;
		    }
		  else
		    {
		      logprintf (LOG_VERBOSE, _("\
The sizes do not match (local %ld) -- retrieving.\n"), local_size);
		    }
		}
	    }
	}	/* opt.timestamping && f->type == FT_PLAINFILE */
      switch (f->type)
	{
