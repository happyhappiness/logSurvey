	{
	  /* Options without arguments: */
	case 132:
	  setoptval ("spider", "on");
	  break;
	case 133:
	  setoptval ("noparent", "on");
	  break;
	case 136:
	  setoptval ("deleteafter", "on");
	  break;
	case 137:
	  setoptval ("retrsymlinks", "on");
	  break;
	case 138:
	  setoptval ("ignorelength", "on");
	  break;
	case 139:
	  setoptval ("passiveftp", "on");
	  break;
	case 141:
	  setoptval ("noclobber", "on");
	  break;
	case 142:
	  setoptval ("followftp", "on");
	  break;
	case 145:
	  setoptval ("cutdirs", optarg);
	  break;
	case 146:
	  setoptval ("verbose", "off");
	  break;
	case 147:
	  setoptval ("dirstruct", "off");
	  break;
	case 148:
	  setoptval ("addhostdir", "off");
	  break;
	case 149:
	  setoptval ("removelisting", "off");
	  break;
	case 155:
	  setoptval ("bindaddress", optarg);
 	  break;
	case 156:
	  setoptval ("httpkeepalive", "off");
	  break;
	case 165:
	  setoptval ("randomwait", "on");
	  break;
	case 'b':
	  setoptval ("background", "on");
	  break;
	case 'c':
	  setoptval ("continue", "on");
	  break;
	case 'd':
#ifdef DEBUG
	  setoptval ("debug", "on");
#else  /* not DEBUG */
	  fprintf (stderr, _("%s: debug support not compiled in.\n"),
		   exec_name);
#endif /* not DEBUG */
	  break;
	case 'E':
	  setoptval ("htmlextension", "on");
	  break;
	case 'F':
	  setoptval ("forcehtml", "on");
	  break;
	case 'H':
	  setoptval ("spanhosts", "on");
	  break;
	case 'h':
	  print_help ();
