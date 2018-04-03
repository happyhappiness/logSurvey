    if (len < RFCNB_Pkt_Hdr_Len) {	/* What a bozo */

#ifdef RFCNB_DEBUG
	fprintf(stderr, "Trying to read less than a packet:");
	perror("");
#endif
	RFCNB_errno = RFCNBE_BadParam;
	return (RFCNBE_Bad);

    }
    /* We discard keep alives here ... */

    if (RFCNB_Timeout > 0)
	alarm(RFCNB_Timeout);

    while (seen_keep_alive) {

	if ((read_len = read(con->fd, hdr, sizeof(hdr))) < 0) {		/* Problems */
#ifdef RFCNB_DEBUG
	    fprintf(stderr, "Reading the packet, we got:");
	    perror("");
#endif
	    if (errno == EINTR)
		RFCNB_errno = RFCNBE_Timeout;
	    else
		RFCNB_errno = RFCNBE_BadRead;
	    RFCNB_saved_errno = errno;
	    return (RFCNBE_Bad);

	}
	/* Now we check out what we got */

	if (read_len == 0) {	/* Connection closed, send back eof?  */

#ifdef RFCNB_DEBUG
	    fprintf(stderr, "Connection closed reading\n");
#endif

	    if (errno == EINTR)
		RFCNB_errno = RFCNBE_Timeout;
	    else
		RFCNB_errno = RFCNBE_ConGone;
	    RFCNB_saved_errno = errno;
	    return (RFCNBE_Bad);

	}
	if (RFCNB_Pkt_Type(hdr) == RFCNB_SESSION_KEEP_ALIVE) {

#ifdef RFCNB_DEBUG
	    fprintf(stderr, "RFCNB KEEP ALIVE received\n");
#endif

	} else {
	    seen_keep_alive = FALSE;
	}

    }

    /* What if we got less than or equal to a hdr size in bytes? */

    if (read_len < sizeof(hdr)) {	/* We got a small packet */

	/* Now we need to copy the hdr portion we got into the supplied packet */

	memcpy(pkt->data, hdr, read_len);	/*Copy data */

#ifdef RFCNB_DEBUG
	RFCNB_Print_Pkt(stderr, "rcvd", pkt, read_len);
#endif

	return (read_len);

    }
    /* Now, if we got at least a hdr size, alloc space for rest, if we need it */
