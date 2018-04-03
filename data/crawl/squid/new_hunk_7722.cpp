	case 'p':
	    dnsServerPathname = xstrdup(optarg);
	    break;
	case 't':
	    dnsServerTCP = 1;
	    break;
	default:
	    fprintf(stderr, "usage: dnsserver -h -d -p socket-filename\n");
	    exit(1);
	    break;
	}
    }

    socket_from_cache = 3;

    /* accept DNS look up from ipcache */
    if (dnsServerPathname || dnsServerTCP) {
	fd = accept(socket_from_cache, NULL, NULL);
	if (dnsServerPathname)
	    unlink(dnsServerPathname);
	if (fd < 0) {
	    fprintf(stderr, "dnsserver: accept: %s\n", xstrerror());
	    exit(1);
