	    fatal_dump("All redirectors have exited!");
	return 0;
    }
    redirector->offset += len;
    redirector->inbuf[redirector->offset] = '\0';
    /* reschedule */
