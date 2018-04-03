 	case 150:
 	  setval ("simplehostcheck", "on");
 	  break;
-	case 154:
-	  /* For debugging purposes.  */
-	  printf ("%s\n", ftp_getaddress ());
-	  exit (0);
-	  break;
 	case 155:
 	  setval ("bindaddress", optarg);
  	  break;
