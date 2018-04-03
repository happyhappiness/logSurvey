	  exit (0);
	  break;
	case 'v':
	  setoptval ("verbose", "on");
	  break;
	case 'x':
	  setoptval ("dirstruct", "on");
	  break;
	case 174:
	  setoptval ("retryconnrefused", "on");
	  break;
	case 177:
	  setoptval ("strictcomments", "on");
	  break;

	  /* Options accepting an argument: */
	case 129:
	  setoptval ("httpuser", optarg);
	  break;
	case 130:
	  setoptval ("httppasswd", optarg);
	  break;
	case 131:
	  setoptval ("header", optarg);
	  break;
	case 134:
	  setoptval ("dotstyle", optarg);
	  break;
	case 135:
	  setoptval ("htmlify", optarg);
	  break;
	case 140:
	  setoptval ("excludedomains", optarg);
	  break;
	case 143:
	  setoptval ("proxyuser", optarg);
	  break;
	case 144:
	  setoptval ("proxypasswd", optarg);
	  break;
	case 151:
	  setoptval ("backups", optarg);
	  break;
	case 152:
	  setoptval ("waitretry", optarg);
	  break;
	case 153:
	  setoptval ("followtags", optarg);
	  break;
	case 160:
	  setoptval ("cookies", optarg);
	  break;
	case 161:
	  setoptval ("loadcookies", optarg);
	  break;
	case 162:
	  setoptval ("savecookies", optarg);
	  break;
	case 163:
	  setoptval ("progress", optarg);
	  break;
	case 164:
	  setoptval ("limitrate", optarg);
	  break;
	case 157:
	  setoptval ("referer", optarg);
	  break;
#ifdef HAVE_SSL
	case 158:
	  setoptval ("sslcertfile", optarg);
	  break;
	case 159:
	  setoptval ("sslcertkey", optarg);
	  break;
	case 166:
	  setoptval ("egdfile", optarg);
	  break;
	case 169:
	  setoptval ("sslcadir", optarg);
	  break;
	case 170:
	  setoptval ("sslcafile", optarg);
	  break;
	case 171:
	  setoptval ("sslcerttype", optarg);
	  break;
	case 172:
	  setoptval ("sslcheckcert", optarg);
	  break;
	case 173:
	  setoptval ("sslprotocol", optarg);
	  break;
#endif /* HAVE_SSL */
	case 167:
	  setoptval ("postdata", optarg);
	  break;
	case 168:
	  setoptval ("postfile", optarg);
	  break;
	case 175:
	  setoptval ("dnscache", optarg);
	  break;
	case 176:
	  setoptval ("restrictfilenames", optarg);
	  break;
	case 'A':
	  setoptval ("accept", optarg);
	  break;
	case 'a':
	  setoptval ("logfile", optarg);
	  append_to_log = 1;
	  break;
	case 'B':
	  setoptval ("base", optarg);
	  break;
	case 'C':
	  setoptval ("cache", optarg);
	  break;
	case 'D':
	  setoptval ("domains", optarg);
	  break;
	case 'e':
	  run_command (optarg);
	  break;
	case 'G':
	  setoptval ("ignoretags", optarg);
	  break;
	case 'g':
	  setoptval ("glob", optarg);
	  break;
	case 'I':
	  setoptval ("includedirectories", optarg);
	  break;
	case 'i':
	  setoptval ("input", optarg);
	  break;
	case 'l':
	  setoptval ("reclevel", optarg);
	  break;
	case 'n':
	  {
