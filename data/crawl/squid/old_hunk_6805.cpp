	    _res.options |= RES_DNSRCH;
#endif
	    break;
	case 'h':
	default:
	    fprintf(stderr, "usage: dnsserver -hvd\n");
	    exit(1);
