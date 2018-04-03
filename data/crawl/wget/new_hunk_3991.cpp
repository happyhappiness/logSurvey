	  printf ("%s\n", ftp_getaddress ());
	  exit (0);
	  break;
	case 27:
	  setval ("bindaddress", optarg);
 	  break;
	case 'b':
	  setval ("background", "on");
	  break;
