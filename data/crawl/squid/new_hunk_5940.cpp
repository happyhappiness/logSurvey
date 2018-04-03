    pthread_attr_setschedparam(&globattr, &globsched);
#endif

    /* Initialize request queue */
    if (pthread_mutex_init(&(request_queue.mutex), NULL))
	fatal("Failed to create mutex");
    if (pthread_cond_init(&(request_queue.cond), NULL))
	fatal("Failed to create condition variable");
    request_queue.head = NULL;
    request_queue.tailp = &request_queue.head;
    request_queue.requests = 0;
    request_queue.blocked = 0;

    /* Initialize done queue */
    if (pthread_mutex_init(&(done_queue.mutex), NULL))
	fatal("Failed to create mutex");
    if (pthread_cond_init(&(done_queue.cond), NULL))
	fatal("Failed to create condition variable");
    done_queue.head = NULL;
    done_queue.tailp = &done_queue.head;
    done_queue.requests = 0;
    done_queue.blocked = 0;

    /* Create threads and get them to sit in their wait loop */
    aio_thread_pool = memPoolCreate("aio_thread", sizeof(aio_thread_t));
    for (i = 0; i < NUMTHREADS; i++) {
	threadp = memPoolAlloc(aio_thread_pool);
	threadp->status = _THREAD_STARTING;
	threadp->current_req = NULL;
	threadp->requests = 0;
	threadp->next = threads;
	threads = threadp;
	if (pthread_create(&threadp->thread, &globattr, aio_thread_loop, threadp)) {
	    fprintf(stderr, "Thread creation failed\n");
	    threadp->status = _THREAD_FAILED;
	    continue;
	}
    }

    /* Create request pool */
