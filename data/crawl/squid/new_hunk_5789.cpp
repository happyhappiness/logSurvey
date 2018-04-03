    done_queue.blocked = 0;

    /* Create threads and get them to sit in their wait loop */
    squidaio_thread_pool = memPoolCreate("aio_thread", sizeof(squidaio_thread_t));
    for (i = 0; i < NUMTHREADS; i++) {
	threadp = memPoolAlloc(squidaio_thread_pool);
	threadp->status = _THREAD_STARTING;
	threadp->current_req = NULL;
	threadp->requests = 0;
	threadp->next = threads;
	threads = threadp;
	if (pthread_create(&threadp->thread, &globattr, squidaio_thread_loop, threadp)) {
	    fprintf(stderr, "Thread creation failed\n");
	    threadp->status = _THREAD_FAILED;
	    continue;
	}
    }

    /* Create request pool */
    squidaio_request_pool = memPoolCreate("aio_request", sizeof(squidaio_request_t));
    squidaio_large_bufs = memPoolCreate("squidaio_large_bufs", AIO_LARGE_BUFS);
    squidaio_medium_bufs = memPoolCreate("squidaio_medium_bufs", AIO_MEDIUM_BUFS);
    squidaio_small_bufs = memPoolCreate("squidaio_small_bufs", AIO_SMALL_BUFS);
    squidaio_tiny_bufs = memPoolCreate("squidaio_tiny_bufs", AIO_TINY_BUFS);
    squidaio_micro_bufs = memPoolCreate("squidaio_micro_bufs", AIO_MICRO_BUFS);

    squidaio_initialised = 1;
}


static void *
squidaio_thread_loop(void *ptr)
{
    squidaio_thread_t *threadp = ptr;
    squidaio_request_t *request;
    sigset_t new;

    /*
