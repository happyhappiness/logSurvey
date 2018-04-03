  make_access ();
  if (getloadavg (&load, 1) != 1)
    {
      static int lossage = 0;
      /* Complain only once for the same error.  */
      if (lossage == 0 || errno != lossage)
	perror_with_name ("cannot enforce load limit: ", "getloadavg");
      lossage = errno;
      load = 0;
    }
