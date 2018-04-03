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
	case 155:
	  setval ("bindaddress", optarg);
 	  break;
	case 156:
	  setval ("httpkeepalive", "off");
	  break;
	case 165:
	  setval ("randomwait", "on");
	  break;
	case 'b':
	  setval ("background", "on");
	  break;
	case 'c':
	  setval ("continue", "on");
	  break;
	case 'd':
#ifdef DEBUG
	  setval ("debug", "on");
#else  /* not DEBUG */
	  fprintf (stderr, _("%s: debug support not compiled in.\n"),
		   exec_name);
#endif /* not DEBUG */
	  break;
	case 'E':
	  setval ("htmlextension", "on");
	  break;
	case 'F':
	  setval ("forcehtml", "on");
	  break;
	case 'H':
	  setval ("spanhosts", "on");
	  break;
	case 'h':
	  print_help ();
