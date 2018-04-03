	/* end of reply found */
	debug(29, 3) ("helperStatefulHandleRead: end of reply found\n");
	*t = '\0';
	if (cbdataReferenceValid(r->data)) {
	    switch ((r->callback(r->data, srv, srv->buf))) {	/*if non-zero reserve helper */
	    case S_HELPER_UNKNOWN:
		fatal("helperStatefulHandleRead: either a non-state aware callback was give to the stateful helper routines, or an uninitialised callback response was recieved.\n");
