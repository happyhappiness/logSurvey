    do {
	if (sec > 60)
	    fatal_dump(NULL);
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_ZERO(&exceptfds);
