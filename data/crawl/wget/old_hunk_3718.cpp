      switch (c)
	{
	  /* Options without arguments: */
	case 4:
	  setval ("spider", "on");
	  break;
	case 5:
	  setval ("noparent", "on");
	  break;
	case 8:
	  setval ("deleteafter", "on");
	  break;
	case 9:
	  setval ("retrsymlinks", "on");
	  break;
	case 10:
	  setval ("ignorelength", "on");
	  break;
	case 11:
	  setval ("passiveftp", "on");
	  break;
	case 13:
	  setval ("noclobber", "on");
	  break;
	case 14:
	  setval ("followftp", "on");
	  break;
	case 17:
	  setval ("cutdirs", optarg);
	  break;
	case 18:
	  setval ("verbose", "off");
	  break;
	case 19:
	  setval ("dirstruct", "off");
	  break;
	case 20:
	  setval ("addhostdir", "off");
	  break;
	case 21:
	  setval ("removelisting", "off");
	  break;
	case 22:
	  setval ("simplehostcheck", "on");
	  break;
	case 26:
	  /* For debugging purposes.  */
	  printf ("%s\n", ftp_getaddress ());
	  exit (0);
	  break;
	case 27:
	  setval ("bindaddress", optarg);
 	  break;
	case 28:
	  setval ("httpkeepalive", "off");
	  break;
	case 'b':
