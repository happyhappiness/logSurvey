  if (infile == 0)
    {
      if (type != 1)
	perror_with_name ("fopen: ", filename);
      return;
    }

