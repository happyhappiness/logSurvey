      switch (c)
	{
	  /* Options without arguments: */
	case 132:
	  setval ("spider", "on");
	  break;
	case 133:
	  setval ("noparent", "on");
	  break;
	case 136:
	  setval ("deleteafter", "on");
	  break;
	case 137:
	  setval ("retrsymlinks", "on");
	  break;
	case 138:
	  setval ("ignorelength", "on");
	  break;
	case 139:
	  setval ("passiveftp", "on");
	  break;
	case 141:
	  setval ("noclobber", "on");
	  break;
	case 142:
	  setval ("followftp", "on");
	  break;
	case 145:
	  setval ("cutdirs", optarg);
	  break;
	case 146:
	  setval ("verbose", "off");
	  break;
	case 147:
	  setval ("dirstruct", "off");
	  break;
	case 148:
	  setval ("addhostdir", "off");
	  break;
	case 149:
	  setval ("removelisting", "off");
	  break;
	case 150:
	  setval ("simplehostcheck", "on");
	  break;
	case 154:
	  /* For debugging purposes.  */
	  printf ("%s\n", ftp_getaddress ());
	  exit (0);
	  break;
	case 155:
	  setval ("bindaddress", optarg);
 	  break;
	case 156:
	  setval ("httpkeepalive", "off");
	  break;
	case 'b':
