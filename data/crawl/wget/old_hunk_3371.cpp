	  exit (0);
	  break;
	case 'K':
	  setval ("backupconverted", "on");
	  break;
	case 'k':
	  setval ("convertlinks", "on");
	  break;
	case 'L':
	  setval ("relativeonly", "on");
	  break;
	case 'm':
	  setval ("mirror", "on");
	  break;
	case 'N':
	  setval ("timestamping", "on");
	  break;
	case 'p':
	  setval ("pagerequisites", "on");
	  break;
	case 'S':
	  setval ("serverresponse", "on");
	  break;
	case 's':
	  setval ("saveheaders", "on");
	  break;
	case 'q':
	  setval ("quiet", "on");
	  break;
	case 'r':
	  setval ("recursive", "on");
	  break;
	case 'V':
	  printf ("GNU Wget %s\n\n", version_string);
