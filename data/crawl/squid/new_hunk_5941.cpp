	    request->ret = -1;
	    request->err = EINTR;
	}
	threadp->status = _THREAD_DONE;
	/* put the request in the done queue */
	pthread_mutex_lock(&done_queue.mutex);
	*done_queue.tailp = request;
	done_queue.tailp = &request->next;
	pthread_mutex_unlock(&done_queue.mutex);
	threadp->requests++;
    }				/* while forever */
    return NULL;
}				/* aio_thread_loop */

static void
aio_queue_request(aio_request_t * request)
{
    static int high_start = 0;
    debug(41, 9) ("aio_queue_request: %p type=%d result=%p\n",
	    request, request->request_type, request->resultp);
    /* Mark it as not executed (failing result, no error) */
    request->ret = -1;
    request->err = 0;
    /* Internal housekeeping */
    request_queue_len += 1;
    request->resultp->_data = request;
    /* Play some tricks with the request_queue2 queue */
    request->next = NULL;
    if (!request_queue2.head) {
	if (pthread_mutex_trylock(&request_queue.mutex) == 0) {
	    /* Normal path */
	    *request_queue.tailp = request;
	    request_queue.tailp = &request->next;
	    pthread_cond_signal(&request_queue.cond);
	    pthread_mutex_unlock(&request_queue.mutex);
    } else {
	    /* Oops, the request queue is blocked, use request_queue2 */
	    *request_queue2.tailp = request;
	    request_queue2.tailp = &request->next;
    }
    } else {
	/* Secondary path. We have blocked requests to deal with */
	/* add the request to the chain */
	*request_queue2.tailp = request;
	if (pthread_mutex_trylock(&request_queue.mutex) == 0) {
	    /* Ok, the queue is no longer blocked */
	    *request_queue.tailp = request_queue2.head;
	    request_queue.tailp = &request->next;
	    pthread_cond_signal(&request_queue.cond);
	    pthread_mutex_unlock(&request_queue.mutex);
	    request_queue2.head = NULL;
	    request_queue2.tailp = &request_queue2.head;
	} else {
	    /* still blocked, bump the blocked request chain */
	    request_queue2.tailp = &request->next;
	}
    }
    if (request_queue2.head) {
	static int filter = 0;
	static int filter_limit = 8;
	if (++filter >= filter_limit) {
	    filter_limit += filter;
	    filter = 0;
	    debug(43, 1) ("aio_queue_request: WARNING - Queue congestion\n");
	}
    }
    /* Warn if out of threads */
    if (request_queue_len > MAGIC1) {
	static int last_warn = 0;
	static int queue_high, queue_low;
	if (high_start == 0) {
	    high_start = squid_curtime;
	    queue_high = request_queue_len;
