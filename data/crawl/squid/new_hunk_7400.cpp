	    fatal_dump("All redirectors have exited!");
	return 0;
    }
    if (len != 1)
	RedirectStats.rewrites[redirector->index]++;
    redirector->offset += len;
    redirector->inbuf[redirector->offset] = '\0';
    /* reschedule */
