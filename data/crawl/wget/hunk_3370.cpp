 	{
 	  /* Options without arguments: */
 	case 132:
-	  setval ("spider", "on");
+	  setoptval ("spider", "on");
 	  break;
 	case 133:
-	  setval ("noparent", "on");
+	  setoptval ("noparent", "on");
 	  break;
 	case 136:
-	  setval ("deleteafter", "on");
+	  setoptval ("deleteafter", "on");
 	  break;
 	case 137:
-	  setval ("retrsymlinks", "on");
+	  setoptval ("retrsymlinks", "on");
 	  break;
 	case 138:
-	  setval ("ignorelength", "on");
+	  setoptval ("ignorelength", "on");
 	  break;
 	case 139:
-	  setval ("passiveftp", "on");
+	  setoptval ("passiveftp", "on");
 	  break;
 	case 141:
-	  setval ("noclobber", "on");
+	  setoptval ("noclobber", "on");
 	  break;
 	case 142:
-	  setval ("followftp", "on");
+	  setoptval ("followftp", "on");
 	  break;
 	case 145:
-	  setval ("cutdirs", optarg);
+	  setoptval ("cutdirs", optarg);
 	  break;
 	case 146:
-	  setval ("verbose", "off");
+	  setoptval ("verbose", "off");
 	  break;
 	case 147:
-	  setval ("dirstruct", "off");
+	  setoptval ("dirstruct", "off");
 	  break;
 	case 148:
-	  setval ("addhostdir", "off");
+	  setoptval ("addhostdir", "off");
 	  break;
 	case 149:
-	  setval ("removelisting", "off");
+	  setoptval ("removelisting", "off");
 	  break;
 	case 155:
-	  setval ("bindaddress", optarg);
+	  setoptval ("bindaddress", optarg);
  	  break;
 	case 156:
-	  setval ("httpkeepalive", "off");
+	  setoptval ("httpkeepalive", "off");
 	  break;
 	case 165:
-	  setval ("randomwait", "on");
+	  setoptval ("randomwait", "on");
 	  break;
 	case 'b':
-	  setval ("background", "on");
+	  setoptval ("background", "on");
 	  break;
 	case 'c':
-	  setval ("continue", "on");
+	  setoptval ("continue", "on");
 	  break;
 	case 'd':
 #ifdef DEBUG
-	  setval ("debug", "on");
+	  setoptval ("debug", "on");
 #else  /* not DEBUG */
 	  fprintf (stderr, _("%s: debug support not compiled in.\n"),
 		   exec_name);
 #endif /* not DEBUG */
 	  break;
 	case 'E':
-	  setval ("htmlextension", "on");
+	  setoptval ("htmlextension", "on");
 	  break;
 	case 'F':
-	  setval ("forcehtml", "on");
+	  setoptval ("forcehtml", "on");
 	  break;
 	case 'H':
-	  setval ("spanhosts", "on");
+	  setoptval ("spanhosts", "on");
 	  break;
 	case 'h':
 	  print_help ();
