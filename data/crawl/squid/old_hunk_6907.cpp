	    continue;
	} else if (x == 0) {
	    assert(Requests != NULL);
	    fprintf(stderr, "TIMEOUT waiting for %s\n", Requests->url);
	    continue;
	}
	if (FD_ISSET(pconn_fd, &R)) {
	    if (read_reply(pconn_fd) != 0)
		pconn_fd = -1;
	}