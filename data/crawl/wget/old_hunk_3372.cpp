	  exit (0);
	  break;
	case 'v':
	  setval ("verbose", "on");
	  break;
	case 'x':
	  setval ("dirstruct", "on");
	  break;
	case 174:
	  setval ("retryconnrefused", "on");
	  break;
	case 177:
	  setval ("strictcomments", "on");
	  break;

	  /* Options accepting an argument: */
	case 129:
	  setval ("httpuser", optarg);
	  break;
	case 130:
	  setval ("httppasswd", optarg);
	  break;
	case 131:
	  setval ("header", optarg);
	  break;
	case 134:
	  setval ("dotstyle", optarg);
	  break;
	case 135:
	  setval ("htmlify", optarg);
	  break;
	case 140:
	  setval ("excludedomains", optarg);
	  break;
	case 143:
	  setval ("proxyuser", optarg);
	  break;
	case 144:
	  setval ("proxypasswd", optarg);
	  break;
	case 151:
	  setval ("backups", optarg);
	  break;
	case 152:
	  setval ("waitretry", optarg);
	  break;
	case 153:
	  setval ("followtags", optarg);
	  break;
	case 160:
	  setval ("cookies", optarg);
	  break;
	case 161:
	  setval ("loadcookies", optarg);
	  break;
	case 162:
	  setval ("savecookies", optarg);
	  break;
	case 163:
	  setval ("progress", optarg);
	  break;
	case 164:
	  setval ("limitrate", optarg);
	  break;
	case 157:
	  setval ("referer", optarg);
	  break;
#ifdef HAVE_SSL
	case 158:
	  setval ("sslcertfile", optarg);
	  break;
	case 159:
	  setval ("sslcertkey", optarg);
	  break;
	case 166:
	  setval ("egdfile", optarg);
	  break;
	case 169:
	  setval ("sslcadir", optarg);
	  break;
	case 170:
	  setval ("sslcafile", optarg);
	  break;
	case 171:
	  setval ("sslcerttype", optarg);
	  break;
	case 172:
	  setval ("sslcheckcert", optarg);
	  break;
	case 173:
	  setval ("sslprotocol", optarg);
	  break;
#endif /* HAVE_SSL */
	case 167:
	  setval ("postdata", optarg);
	  break;
	case 168:
	  setval ("postfile", optarg);
	  break;
	case 175:
	  setval ("dnscache", optarg);
	  break;
	case 176:
	  setval ("restrictfilenames", optarg);
	  break;
	case 'A':
	  setval ("accept", optarg);
	  break;
	case 'a':
	  setval ("logfile", optarg);
	  append_to_log = 1;
	  break;
	case 'B':
	  setval ("base", optarg);
	  break;
	case 'C':
	  setval ("cache", optarg);
	  break;
	case 'D':
	  setval ("domains", optarg);
	  break;
	case 'e':
	  {
	    char *com, *val;
	    if (parse_line (optarg, &com, &val))
	      {
		if (!setval (com, val))
		  exit (1);
	      }
	    else
	      {
		fprintf (stderr, _("%s: %s: invalid command\n"), exec_name,
			 optarg);
		exit (1);
	      }
	    xfree (com);
	    xfree (val);
	  }
	  break;
	case 'G':
	  setval ("ignoretags", optarg);
	  break;
	case 'g':
	  setval ("glob", optarg);
	  break;
	case 'I':
	  setval ("includedirectories", optarg);
	  break;
	case 'i':
	  setval ("input", optarg);
	  break;
	case 'l':
	  setval ("reclevel", optarg);
	  break;
	case 'n':
	  {
