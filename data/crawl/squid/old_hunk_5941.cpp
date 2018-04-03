	    request->ret = -1;
	    request->err = EINTR;
	}
	threadp->req = NULL;	/* tells main thread that we are done */
    }				/* while */
    return NULL;
}				/* aio_thread_loop */

static void
aio_do_request(aio_request_t * requestp)
{
    if (wait_threads == NULL && busy_threads_head == NULL) {
	fprintf(stderr, "PANIC: No threads to service requests with!\n");
	exit(-1);
    }
    aio_queue_request(requestp);
}				/* aio_do_request */


static void
aio_queue_request(aio_request_t * requestp)
{
    aio_request_t *rp;
    static int last_warn = 0;
    static int high_start = 0;
    static int queue_high, queue_low;
    int i;

    /* Mark it as not executed (failing result, no error) */
    requestp->ret = -1;
    requestp->err = 0;
    /* Queue it on the request queue */
    if (request_queue_head == NULL) {
	request_queue_head = requestp;
	request_queue_tail = requestp;
    } else {
	request_queue_tail->next = requestp;
	request_queue_tail = requestp;
    }
    requestp->next = NULL;
    request_queue_len += 1;
    /* Poll done threads if needed */
    if (wait_threads == NULL)
	aio_poll_threads();
    /* Kick it rolling */
    aio_process_request_queue();
    /* Warn if out of threads */
    if (request_queue_len > (NUMTHREADS >> 1)) {
	if (high_start == 0) {
	    high_start = squid_curtime;
	    queue_high = request_queue_len;
