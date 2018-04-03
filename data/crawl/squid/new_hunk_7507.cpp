	    if (!logfile)
		fprintf(stderr, "Could not open dnsserver's log file\n");
	    break;
	case 'h':
	default:
	    fprintf(stderr, "usage: dnsserver -hvd\n");
	    exit(1);
	    break;
	}
    }

    while (1) {
	int retry_count = 0;
	int addrbuf;