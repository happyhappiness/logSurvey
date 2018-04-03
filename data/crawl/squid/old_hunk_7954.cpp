	case '?':
	case 'h':
	default:
	    printf("\
Usage: cached [-Rsehvz] [-f config-file] [-[apu] port]\n\
       -e        Print messages to stderr.\n\
       -h        Print help message.\n\
       -s        Disable syslog output.\n\
       -v        Print version.\n\
       -z        Zap disk storage -- deletes all objects in disk cache.\n\
       -C        Do not catch fatal signals.\n\
       -D        Disable initial DNS tests.\n\
       -R        Do not set REUSEADDR on port.\n\
       -f file   Use given config-file instead of\n\
                 $HARVEST_HOME/lib/cached.conf.\n\
       -a port	 Specify ASCII port number (default: %d).\n\
       -u port	 Specify UDP port number (default: %d).\n",
		CACHE_HTTP_PORT, CACHE_ICP_PORT);

	    exit(1);
	    break;
	}

