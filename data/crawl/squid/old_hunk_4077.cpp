    /* use an iovec ...                                                    */

    if (len < pkt_len)		/* Only get as much as we have space for */
	more = len - RFCNB_Pkt_Hdr_Len;
    else
	more = pkt_len;

    this_time = 0;

    /* We read for each fragment ... */

    if (pkt->len == read_len) {	/* If this frag was exact size */
	pkt_frag = pkt->next;	/* Stick next lot in next frag */
	offset = 0;		/* then we start at 0 in next  */
    } else {
	pkt_frag = pkt;		/* Otherwise use rest of this frag */
	offset = RFCNB_Pkt_Hdr_Len;	/* Otherwise skip the header       */
    }

    frag_len = pkt_frag->len;

    if (more <= frag_len)	/* If len left to get less than frag space */
	this_len = more;	/* Get the rest ...                        */
    else
	this_len = frag_len - offset;

    while (more > 0) {

	if ((this_time = read(con->fd, (pkt_frag->data) + offset, this_len)) <= 0) {	/* Problems */

	    if (errno == EINTR) {

		RFCNB_errno = RFCNB_Timeout;

	    } else {
		if (this_time < 0)
		    RFCNB_errno = RFCNBE_BadRead;
		else
		    RFCNB_errno = RFCNBE_ConGone;
	    }

	    RFCNB_saved_errno = errno;
	    return (RFCNBE_Bad);

	}
#ifdef RFCNB_DEBUG
	fprintf(stderr, "Frag_Len = %i, this_time = %i, this_len = %i, more = %i\n", frag_len,
	    this_time, this_len, more);
#endif

	read_len = read_len + this_time;	/* How much have we read ... */

	/* Now set up the next part */

	if (pkt_frag->next == NULL)
	    break;		/* That's it here */

	pkt_frag = pkt_frag->next;
	this_len = pkt_frag->len;
	offset = 0;

	more = more - this_time;

    }

