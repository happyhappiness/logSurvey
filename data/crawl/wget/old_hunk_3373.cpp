	      switch (*p)
		{
		case 'v':
		  setval ("verbose", "off");
		  break;
		case 'H':
		  setval ("addhostdir", "off");
		  break;
		case 'd':
		  setval ("dirstruct", "off");
		  break;
		case 'c':
		  setval ("noclobber", "on");
		  break;
		case 'r':
		  setval ("removelisting", "off");
		  break;
		case 'p':
		  setval ("noparent", "on");
		  break;
		case 'k':
		  setval ("httpkeepalive", "off");
		  break;
		default:
		  printf (_("%s: illegal option -- `-n%c'\n"), exec_name, *p);
