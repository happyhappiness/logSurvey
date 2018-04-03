		}
	    break;
	  }
	case 'O':
	  setoptval ("outputdocument", optarg);
	  break;
	case 'o':
	  setoptval ("logfile", optarg);
	  break;
	case 'P':
	  setoptval ("dirprefix", optarg);
	  break;
	case 'Q':
	  setoptval ("quota", optarg);
	  break;
	case 'R':
	  setoptval ("reject", optarg);
	  break;
	case 'T':
	  setoptval ("timeout", optarg);
	  break;
	case 't':
	  setoptval ("tries", optarg);
	  break;
	case 'U':
	  setoptval ("useragent", optarg);
	  break;
	case 'w':
	  setoptval ("wait", optarg);
	  break;
	case 'X':
	  setoptval ("excludedirectories", optarg);
	  break;
	case 'Y':
	  setoptval ("useproxy", optarg);
	  break;

	case '?':
	  print_usage ();
	  printf ("\n");
	  printf (_("Try `%s --help' for more options.\n"), exec_name);
	  exit (0);
	  break;
	}
    }

  /* All user options have now been processed, so it's now safe to do
