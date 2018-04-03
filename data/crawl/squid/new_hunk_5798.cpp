 * I'll make it much more optimal later.
 */
int
a_file_callback(async_queue_t * q)
{
    int i;
    int completed = 0;
    int retval, reterr;
    DRCB *rc;
    DWCB *wc;
    FREE *freefunc;
    void *callback_data;
    void *buf;
    int fd;
    async_queue_entry_t *aqe;
    async_queue_entry_type_t type;

    assert(q->aq_state == AQ_STATE_SETUP);

    /* Loop through all slots */
    for (i = 0; i < MAX_ASYNCOP; i++) {
	if (q->aq_queue[i].aq_e_state == AQ_ENTRY_USED) {
	    aqe = &q->aq_queue[i];
	    /* Active, get status */
	    reterr = aio_error(&aqe->aq_e_aiocb);
	    if (reterr < 0) {
		fatal("aio_error returned an error!\n");
	    }
	    if (reterr != EINPROGRESS) {
		/* Get the return code */
		retval = aio_return(&aqe->aq_e_aiocb);

		/* Get the callback parameters */
		callback_data = aqe->aq_e_callback_data;
		freefunc = aqe->aq_e_free;
		rc = aqe->aq_e_callback.read;
		wc = aqe->aq_e_callback.write;
		buf = aqe->aq_e_buf;
		fd = aqe->aq_e_fd;
		type = aqe->aq_e_type;

		/* Free slot */
		bzero(aqe, sizeof(async_queue_entry_t));
		aqe->aq_e_state = AQ_ENTRY_FREE;
		q->aq_numpending--;

		/* Callback */
		if (cbdataValid(callback_data)) {
		    if (type == AQ_ENTRY_READ)
			rc(fd, buf, retval, reterr, callback_data);
		    if (type == AQ_ENTRY_WRITE)
			wc(fd, reterr, retval, callback_data);
		}
		cbdataUnlock(callback_data);
		if (type == AQ_ENTRY_WRITE && freefunc)
		    freefunc(buf);
	    }
	}
    }
    return completed;
}


void
a_file_setupqueue(async_queue_t * q)
{
    int i;

    /* Make sure the queue isn't setup */
    assert(q->aq_state == AQ_STATE_NONE);

    /* Loop through, blanking the queue entries */

    /* Done */
    q->aq_state = AQ_STATE_SETUP;

}


void
a_file_syncqueue(async_queue_t * q)
{
    assert(q->aq_state == AQ_STATE_SETUP);

    /*
     * Keep calling callback to complete ops until the queue is empty
     * We can't quit when callback returns 0 - some calls may not
     * return any completed pending events, but they're still pending!
     */
    while (q->aq_numpending)
	a_file_callback(q);
}


void
a_file_closequeue(async_queue_t * q)
{
    assert(q->aq_state == AQ_STATE_SETUP);

    a_file_syncqueue(q);
    q->aq_state = AQ_STATE_NONE;
}
