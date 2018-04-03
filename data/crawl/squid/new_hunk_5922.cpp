    }
    while (!done_reading_urls || noutstanding) {
	if (!opt_reopen && pconn_fd < 0) {
	    fprintf(stderr, "TERMINATED: Connection closed\n");
	    break;
	}
	if (pconn_fd < 0) {
	    pconn_fd = open_http_socket();
	    if (pconn_fd < 0) {
		perror("socket");
		exit(1);
	    }
	    nextr = Requests;
	    Requests = NULL;
	    noutstanding = 0;
	    while ((r = nextr) != NULL) {
		nextr = r->next;
		if (send_request(pconn_fd, r->url) != 0) {
		    close(pconn_fd);
		    pconn_fd = -1;
		    nextr = r;
		    for (r = Requests; r != NULL && r->next; r = r->next);
		    if (r != NULL)
			r->next = nextr;
		    else
