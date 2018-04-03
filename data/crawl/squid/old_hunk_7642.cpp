    timeout = squid_curtime + sec;

    do {
	if (0 < failtime && failtime < squid_curtime)
	    break;
