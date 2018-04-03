     * For each request outstanding, add it's socket to the fdset,
     * and if it is the earliest timeout to expire, mark it as lowest.
     */
    for (slp = Sessions; slp; slp = slp->next) {
	active++;
	isp = slp->internal;
	if ((isp->sd + 1) > *numfds)
	    *numfds = (isp->sd + 1);
	FD_SET(isp->sd, fdset);
	if (isp->requests) {
	    /* found another session with outstanding requests */
	    requests++;
	    for (rp = isp->requests; rp; rp = rp->next_request) {
		if (!timerisset(&earliest) || timercmp(&rp->expire, &earliest, <))
		    earliest = rp->expire;
	    }
	}
    }
    if (requests == 0)		/* if none are active, skip arithmetic */
	return active;

    /*
     * Now find out how much time until the earliest timeout.  This
     * transforms earliest from an absolute time into a delta time, the
     * time left until the select should timeout.
     */
    gettimeofday(&now, (struct timezone *) 0);
    earliest.tv_sec--;		/* adjust time to make arithmetic easier */
    earliest.tv_usec += 1000000L;
    earliest.tv_sec -= now.tv_sec;
    earliest.tv_usec -= now.tv_usec;
    while (earliest.tv_usec >= 1000000L) {
	earliest.tv_usec -= 1000000L;
	earliest.tv_sec += 1;
    }
    if (earliest.tv_sec < 0) {
	earliest.tv_sec = 0;
	earliest.tv_usec = 0;
    }
    /* if it was blocking before or our delta time is less, reset timeout */
    if (*block == 1 || timercmp(&earliest, timeout, <)) {
	*timeout = earliest;
	*block = 0;
    }
    return active;
}

/* 
 * snmp_timeout should be called whenever the timeout from
 * snmp_select_info expires, but it is idempotent, so snmp_timeout can
 * be polled (probably a cpu expensive proposition).  snmp_timeout
 * checks to see if any of the sessions have an outstanding request
 * that has timed out.  If it finds one (or more), and that pdu has
 * more retries available, a new packet is formed from the pdu and is
 * resent.  If there are no more retries available, the callback for
 * the session is used to alert the user of the timeout.
 */
void
snmp_timeout(void)
{
    struct session_list *slp;
    struct snmp_session *sp;
    struct snmp_internal_session *isp;
    struct request_list *rp, *rp_next = 0;
    struct timeval now;

    gettimeofday(&now, (struct timezone *) 0);
    /*
     * For each request outstanding, check to see if it has expired.
     */
    for (slp = Sessions; slp; slp = slp->next) {
	sp = slp->session;
	isp = slp->internal;
	for (rp = isp->requests; rp; rp = rp_next) {
	    rp_next = rp->next_request;
	    if (timercmp(&rp->expire, &now, <)) {
		/* this timer has expired */
		if (rp->retries >= sp->retries) {
#if DEBUG_SNMPTRACE
		    snmp_print_trace(slp, rp, TRACE_TIMEOUT);
#endif
		    /* No more chances, delete this entry */
		    sp->callback(TIMED_OUT, sp, rp->pdu->reqid, rp->pdu, sp->callback_magic);
		    free_one_request(isp, rp);
		    continue;
		} else {
		    u_char packet[PACKET_LENGTH];
		    int length = PACKET_LENGTH;
		    struct timeval tv;

		    /* retransmit this pdu */
		    rp->retries++;
		    rp->timeout <<= 1;
		    if (snmp_build(sp, rp->pdu, packet, &length, 0) < 0) {
#if NO_PRINTFS
			fprintf(stderr, "Error building packet\n");
#endif
		    }
		    if (snmp_dump_packet) {
			snmp_print_packet((char *)packet, length, rp->pdu->address, 1);
		    }
		    gettimeofday(&tv, (struct timezone *) 0);
		    if (sendto(isp->sd, (char *) packet, length, 0, (struct sockaddr *) &rp->pdu->address, sizeof(rp->pdu->address)) < 0) {
			perror("sendto");
		    }
		    rp->time = tv;
		    tv.tv_usec += rp->timeout;
		    tv.tv_sec += tv.tv_usec / 1000000L;
		    tv.tv_usec %= 1000000L;
		    rp->expire = tv;
#if DEBUG_SNMPTRACE
		    snmp_print_trace(slp, rp, TRACE_SEND);
#endif
		}
	    }
	}
    }
}
