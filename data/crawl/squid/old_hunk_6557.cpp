	memFree(MEM_8K_BUF, redirector->inbuf);
	redirector->inbuf = NULL;
	comm_close(fd);
	if (--NRedirectorsOpen == 0 && !shutdown_pending)
	    fatal_dump("All redirectors have exited!");
	return;
    }