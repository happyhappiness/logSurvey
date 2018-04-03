    if (RFCNB_Timeout > 0)
        alarm(RFCNB_Timeout);

    if ((len_sent = writev(con->fd, io_list, i)) < 0) {         /* An error */

        con->errn = errno;
        if (errno == EINTR)     /* We were interrupted ... */
            RFCNB_errno = RFCNBE_Timeout;
        else
            RFCNB_errno = RFCNBE_BadWrite;
        RFCNB_saved_errno = errno;
        return (RFCNBE_Bad);

    }
    if (len_sent < tot_sent) {  /* Less than we wanted */
        if (errno == EINTR)     /* We were interrupted */
            RFCNB_errno = RFCNBE_Timeout;
        else
            RFCNB_errno = RFCNBE_BadWrite;
        RFCNB_saved_errno = errno;
        return (RFCNBE_Bad);
    }
    if (RFCNB_Timeout > 0)
        alarm(0);               /* Reset that sucker */

#ifdef RFCNB_DEBUG

    fprintf(stderr, "Len sent = %i ...\n", len_sent);
    RFCNB_Print_Pkt(stderr, "sent", pkt, len_sent);     /* Print what send ... */

#endif

    return (len_sent);

}

/* Read an RFCNB packet off the connection.
 *
 * We read the first 4 bytes, that tells us the length, then read the
 * rest. We should implement a timeout, but we don't just yet
 *
 */


int
RFCNB_Get_Pkt(struct RFCNB_Con *con, struct RFCNB_Pkt *pkt, int len)
{
    int read_len, pkt_len;
    char hdr[RFCNB_Pkt_Hdr_Len];        /* Local space for the header */
    struct RFCNB_Pkt *pkt_frag;
    int more, this_time, offset, frag_len, this_len;
    BOOL seen_keep_alive = TRUE;

    /* Read that header straight into the buffer */

    if (len < RFCNB_Pkt_Hdr_Len) {      /* What a bozo */

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

        if ((read_len = read(con->fd, hdr, sizeof(hdr))) < 0) {         /* Problems */
#ifdef RFCNB_DEBUG
            fprintf(stderr, "Reading the packet, we got:");
            perror("");
