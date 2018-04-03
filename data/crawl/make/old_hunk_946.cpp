	cptr++;
      if (*cptr == 0)
	break;
      if (debug_flag)
	printf ("argv[%d] = [%s]\n", argc, cptr);
      argv[argc++] = cptr;
      while ((*cptr != 0)
	     && (!isspace(*cptr)))
