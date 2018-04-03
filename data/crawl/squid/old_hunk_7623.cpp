    do {
	if (sec > 60)
	    fatal_dump(NULL);
	if (0 < failtime && failtime < squid_curtime)
	    break;

	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_ZERO(&exceptfds);
