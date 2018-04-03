 	      switch (*p)
 		{
 		case 'v':
-		  setval ("verbose", "off");
+		  setoptval ("verbose", "off");
 		  break;
 		case 'H':
-		  setval ("addhostdir", "off");
+		  setoptval ("addhostdir", "off");
 		  break;
 		case 'd':
-		  setval ("dirstruct", "off");
+		  setoptval ("dirstruct", "off");
 		  break;
 		case 'c':
-		  setval ("noclobber", "on");
+		  setoptval ("noclobber", "on");
 		  break;
 		case 'r':
-		  setval ("removelisting", "off");
+		  setoptval ("removelisting", "off");
 		  break;
 		case 'p':
-		  setval ("noparent", "on");
+		  setoptval ("noparent", "on");
 		  break;
 		case 'k':
-		  setval ("httpkeepalive", "off");
+		  setoptval ("httpkeepalive", "off");
 		  break;
 		default:
 		  printf (_("%s: illegal option -- `-n%c'\n"), exec_name, *p);
