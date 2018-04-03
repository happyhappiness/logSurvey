	      switch (*p)
		{
		case 'v':
		  setoptval ("verbose", "off");
		  break;
		case 'H':
		  setoptval ("addhostdir", "off");
		  break;
		case 'd':
		  setoptval ("dirstruct", "off");
		  break;
		case 'c':
		  setoptval ("noclobber", "on");
		  break;
		case 'r':
		  setoptval ("removelisting", "off");
		  break;
		case 'p':
		  setoptval ("noparent", "on");
		  break;
		case 'k':
		  setoptval ("httpkeepalive", "off");
		  break;
		default:
		  printf (_("%s: illegal option -- `-n%c'\n"), exec_name, *p);
