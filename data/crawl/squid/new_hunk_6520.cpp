	    _res.options |= RES_DNSRCH;
#endif
	    break;
	case 's':
	    if (opt_s == 0) {
		_res.nscount = 0;
