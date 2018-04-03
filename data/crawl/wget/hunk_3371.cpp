 	  exit (0);
 	  break;
 	case 'K':
-	  setval ("backupconverted", "on");
+	  setoptval ("backupconverted", "on");
 	  break;
 	case 'k':
-	  setval ("convertlinks", "on");
+	  setoptval ("convertlinks", "on");
 	  break;
 	case 'L':
-	  setval ("relativeonly", "on");
+	  setoptval ("relativeonly", "on");
 	  break;
 	case 'm':
-	  setval ("mirror", "on");
+	  setoptval ("mirror", "on");
 	  break;
 	case 'N':
-	  setval ("timestamping", "on");
+	  setoptval ("timestamping", "on");
 	  break;
 	case 'p':
-	  setval ("pagerequisites", "on");
+	  setoptval ("pagerequisites", "on");
 	  break;
 	case 'S':
-	  setval ("serverresponse", "on");
+	  setoptval ("serverresponse", "on");
 	  break;
 	case 's':
-	  setval ("saveheaders", "on");
+	  setoptval ("saveheaders", "on");
 	  break;
 	case 'q':
-	  setval ("quiet", "on");
+	  setoptval ("quiet", "on");
 	  break;
 	case 'r':
-	  setval ("recursive", "on");
+	  setoptval ("recursive", "on");
 	  break;
 	case 'V':
 	  printf ("GNU Wget %s\n\n", version_string);
