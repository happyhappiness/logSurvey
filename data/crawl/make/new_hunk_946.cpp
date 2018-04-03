	cptr++;
      if (*cptr == 0)
	break;
      DB (DB_JOBS, ("argv[%d] = [%s]\n", argc, cptr));
      argv[argc++] = cptr;
      while ((*cptr != 0)
	     && (!isspace(*cptr)))
