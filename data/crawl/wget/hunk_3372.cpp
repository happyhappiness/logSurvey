 	  exit (0);
 	  break;
 	case 'v':
-	  setval ("verbose", "on");
+	  setoptval ("verbose", "on");
 	  break;
 	case 'x':
-	  setval ("dirstruct", "on");
+	  setoptval ("dirstruct", "on");
 	  break;
 	case 174:
-	  setval ("retryconnrefused", "on");
+	  setoptval ("retryconnrefused", "on");
 	  break;
 	case 177:
-	  setval ("strictcomments", "on");
+	  setoptval ("strictcomments", "on");
 	  break;
 
 	  /* Options accepting an argument: */
 	case 129:
-	  setval ("httpuser", optarg);
+	  setoptval ("httpuser", optarg);
 	  break;
 	case 130:
-	  setval ("httppasswd", optarg);
+	  setoptval ("httppasswd", optarg);
 	  break;
 	case 131:
-	  setval ("header", optarg);
+	  setoptval ("header", optarg);
 	  break;
 	case 134:
-	  setval ("dotstyle", optarg);
+	  setoptval ("dotstyle", optarg);
 	  break;
 	case 135:
-	  setval ("htmlify", optarg);
+	  setoptval ("htmlify", optarg);
 	  break;
 	case 140:
-	  setval ("excludedomains", optarg);
+	  setoptval ("excludedomains", optarg);
 	  break;
 	case 143:
-	  setval ("proxyuser", optarg);
+	  setoptval ("proxyuser", optarg);
 	  break;
 	case 144:
-	  setval ("proxypasswd", optarg);
+	  setoptval ("proxypasswd", optarg);
 	  break;
 	case 151:
-	  setval ("backups", optarg);
+	  setoptval ("backups", optarg);
 	  break;
 	case 152:
-	  setval ("waitretry", optarg);
+	  setoptval ("waitretry", optarg);
 	  break;
 	case 153:
-	  setval ("followtags", optarg);
+	  setoptval ("followtags", optarg);
 	  break;
 	case 160:
-	  setval ("cookies", optarg);
+	  setoptval ("cookies", optarg);
 	  break;
 	case 161:
-	  setval ("loadcookies", optarg);
+	  setoptval ("loadcookies", optarg);
 	  break;
 	case 162:
-	  setval ("savecookies", optarg);
+	  setoptval ("savecookies", optarg);
 	  break;
 	case 163:
-	  setval ("progress", optarg);
+	  setoptval ("progress", optarg);
 	  break;
 	case 164:
-	  setval ("limitrate", optarg);
+	  setoptval ("limitrate", optarg);
 	  break;
 	case 157:
-	  setval ("referer", optarg);
+	  setoptval ("referer", optarg);
 	  break;
 #ifdef HAVE_SSL
 	case 158:
-	  setval ("sslcertfile", optarg);
+	  setoptval ("sslcertfile", optarg);
 	  break;
 	case 159:
-	  setval ("sslcertkey", optarg);
+	  setoptval ("sslcertkey", optarg);
 	  break;
 	case 166:
-	  setval ("egdfile", optarg);
+	  setoptval ("egdfile", optarg);
 	  break;
 	case 169:
-	  setval ("sslcadir", optarg);
+	  setoptval ("sslcadir", optarg);
 	  break;
 	case 170:
-	  setval ("sslcafile", optarg);
+	  setoptval ("sslcafile", optarg);
 	  break;
 	case 171:
-	  setval ("sslcerttype", optarg);
+	  setoptval ("sslcerttype", optarg);
 	  break;
 	case 172:
-	  setval ("sslcheckcert", optarg);
+	  setoptval ("sslcheckcert", optarg);
 	  break;
 	case 173:
-	  setval ("sslprotocol", optarg);
+	  setoptval ("sslprotocol", optarg);
 	  break;
 #endif /* HAVE_SSL */
 	case 167:
-	  setval ("postdata", optarg);
+	  setoptval ("postdata", optarg);
 	  break;
 	case 168:
-	  setval ("postfile", optarg);
+	  setoptval ("postfile", optarg);
 	  break;
 	case 175:
-	  setval ("dnscache", optarg);
+	  setoptval ("dnscache", optarg);
 	  break;
 	case 176:
-	  setval ("restrictfilenames", optarg);
+	  setoptval ("restrictfilenames", optarg);
 	  break;
 	case 'A':
-	  setval ("accept", optarg);
+	  setoptval ("accept", optarg);
 	  break;
 	case 'a':
-	  setval ("logfile", optarg);
+	  setoptval ("logfile", optarg);
 	  append_to_log = 1;
 	  break;
 	case 'B':
-	  setval ("base", optarg);
+	  setoptval ("base", optarg);
 	  break;
 	case 'C':
-	  setval ("cache", optarg);
+	  setoptval ("cache", optarg);
 	  break;
 	case 'D':
-	  setval ("domains", optarg);
+	  setoptval ("domains", optarg);
 	  break;
 	case 'e':
-	  {
-	    char *com, *val;
-	    if (parse_line (optarg, &com, &val))
-	      {
-		if (!setval (com, val))
-		  exit (1);
-	      }
-	    else
-	      {
-		fprintf (stderr, _("%s: %s: invalid command\n"), exec_name,
-			 optarg);
-		exit (1);
-	      }
-	    xfree (com);
-	    xfree (val);
-	  }
+	  run_command (optarg);
 	  break;
 	case 'G':
-	  setval ("ignoretags", optarg);
+	  setoptval ("ignoretags", optarg);
 	  break;
 	case 'g':
-	  setval ("glob", optarg);
+	  setoptval ("glob", optarg);
 	  break;
 	case 'I':
-	  setval ("includedirectories", optarg);
+	  setoptval ("includedirectories", optarg);
 	  break;
 	case 'i':
-	  setval ("input", optarg);
+	  setoptval ("input", optarg);
 	  break;
 	case 'l':
-	  setval ("reclevel", optarg);
+	  setoptval ("reclevel", optarg);
 	  break;
 	case 'n':
 	  {
