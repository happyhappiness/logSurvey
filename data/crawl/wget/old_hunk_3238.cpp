      logfp = fopen (file, appendp ? "a" : "w");
      if (!logfp)
	{
	  perror (opt.lfilename);
	  exit (1);
	}
    }
