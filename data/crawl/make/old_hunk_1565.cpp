      fputs ("Options:\n", stderr);
      for (cs = switches; cs->c != '\0'; ++cs)
	{
	  char buf[1024], arg[50];

	  if (cs->description[0] == '-')
	    continue;
