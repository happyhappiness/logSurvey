       switch (c)
 	{
 	  /* Options without arguments: */
-	case 4:
+	case 132:
 	  setval ("spider", "on");
 	  break;
-	case 5:
+	case 133:
 	  setval ("noparent", "on");
 	  break;
-	case 8:
+	case 136:
 	  setval ("deleteafter", "on");
 	  break;
-	case 9:
+	case 137:
 	  setval ("retrsymlinks", "on");
 	  break;
-	case 10:
+	case 138:
 	  setval ("ignorelength", "on");
 	  break;
-	case 11:
+	case 139:
 	  setval ("passiveftp", "on");
 	  break;
-	case 13:
+	case 141:
 	  setval ("noclobber", "on");
 	  break;
-	case 14:
+	case 142:
 	  setval ("followftp", "on");
 	  break;
-	case 17:
+	case 145:
 	  setval ("cutdirs", optarg);
 	  break;
-	case 18:
+	case 146:
 	  setval ("verbose", "off");
 	  break;
-	case 19:
+	case 147:
 	  setval ("dirstruct", "off");
 	  break;
-	case 20:
+	case 148:
 	  setval ("addhostdir", "off");
 	  break;
-	case 21:
+	case 149:
 	  setval ("removelisting", "off");
 	  break;
-	case 22:
+	case 150:
 	  setval ("simplehostcheck", "on");
 	  break;
-	case 26:
+	case 154:
 	  /* For debugging purposes.  */
 	  printf ("%s\n", ftp_getaddress ());
 	  exit (0);
 	  break;
-	case 27:
+	case 155:
 	  setval ("bindaddress", optarg);
  	  break;
-	case 28:
+	case 156:
 	  setval ("httpkeepalive", "off");
 	  break;
 	case 'b':
