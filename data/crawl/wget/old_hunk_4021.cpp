#endif /* not DEBUG */
	  break;
	case 'E':
	  /* For debugging purposes.  */
	  printf ("%s\n", ftp_getaddress ());
	  exit (0);
	  break;
	case 'F':
	  setval ("forcehtml", "on");
