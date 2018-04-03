	  exit (0);
	  break;
	case 'K':
	  setoptval ("backupconverted", "on");
	  break;
	case 'k':
	  setoptval ("convertlinks", "on");
	  break;
	case 'L':
	  setoptval ("relativeonly", "on");
	  break;
	case 'm':
	  setoptval ("mirror", "on");
	  break;
	case 'N':
	  setoptval ("timestamping", "on");
	  break;
	case 'p':
	  setoptval ("pagerequisites", "on");
	  break;
	case 'S':
	  setoptval ("serverresponse", "on");
	  break;
	case 's':
	  setoptval ("saveheaders", "on");
	  break;
	case 'q':
	  setoptval ("quiet", "on");
	  break;
	case 'r':
	  setoptval ("recursive", "on");
	  break;
	case 'V':
	  printf ("GNU Wget %s\n\n", version_string);
