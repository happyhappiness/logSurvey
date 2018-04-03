	    fd, redirector->index + 1);
	redirector->flags = 0;
	comm_close(fd);
	if (--NRedirectorsOpen == 0)
	    fatal_dump("All redirectors have exited!");
	return 0;
    }
