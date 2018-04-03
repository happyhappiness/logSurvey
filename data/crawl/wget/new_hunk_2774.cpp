	      free_hstat (&hstat);
	      continue;
	    }
	  else
	    /* Getting here would mean reading more data than
	       requested with content-length, which we never do.  */
	    abort ();
	}
      else			/* now hstat.res can only be -1 */
	{
