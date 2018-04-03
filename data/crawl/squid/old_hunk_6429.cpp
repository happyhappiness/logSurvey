    static int pconn_fd = -1;
    static char buf[8192];
    struct timeval to;
    fd_set R;
    struct _r *r;
    struct _r *nextr;
    int x;
    int timeouts;
    while (!done_reading_urls || noutstanding) {
	if (timeouts == 20) {
	    close(pconn_fd);
	    pconn_fd = -1;
	    r = Requests;
	    Requests = Requests->next;
	    free(r);
	    noutstanding--;
	}
	if (pconn_fd < 0) {
	    pconn_fd = open_http_socket();
	    if (pconn_fd < 0) {
		perror("socket");
		exit(1);
	    }
	    nextr = Requests;
	    Requests = NULL;
	    while ((r = nextr) != NULL) {
		nextr = r->next;
		send_request(pconn_fd, r->url);
		free(r);
		noutstanding--;
	    }
	    timeouts = 0;
	}
	if (noutstanding < 10 && !done_reading_urls) {
	    char *t;
	    if (fgets(buf, 8191, stdin) == NULL) {
		printf("Done Reading URLS\n");
		done_reading_urls = 1;
		break;
	    }
	    if ((t = strchr(buf, '\n')))
		*t = '\0';
	    send_request(pconn_fd, buf);
	    timeouts = 0;
	}
	FD_ZERO(&R);
