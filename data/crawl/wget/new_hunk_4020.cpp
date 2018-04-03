	case 22:
	  setval ("simplehostcheck", "on");
	  break;
	case 26:
	  /* For debugging purposes.  */
	  printf ("%s\n", ftp_getaddress ());
	  exit (0);
	  break;
	case 'b':
	  setval ("background", "on");
	  break;
