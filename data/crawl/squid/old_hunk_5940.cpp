    pthread_attr_setschedparam(&globattr, &globsched);
#endif

    /* Create threads and get them to sit in their wait loop */
    threads = xcalloc(NUMTHREADS, sizeof(aio_thread_t));

    for (i = 0; i < NUMTHREADS; i++) {
	threadp = &threads[i];
	threadp->status = _THREAD_STARTING;
	if (pthread_mutex_init(&(threadp->mutex), NULL)) {
	    threadp->status = _THREAD_FAILED;
	    continue;
	}
	if (pthread_cond_init(&(threadp->cond), NULL)) {
	    threadp->status = _THREAD_FAILED;
	    continue;
	}
	threadp->req = NULL;
	threadp->processed_req = NULL;
	if (pthread_create(&threadp->thread, &globattr, aio_thread_loop, threadp)) {
	    fprintf(stderr, "Thread creation failed\n");
	    threadp->status = _THREAD_FAILED;
	    continue;
	}
	threadp->next = wait_threads;
	wait_threads = threadp;
#if AIO_PROPER_MUTEX
	pthread_mutex_lock(&threadp->mutex);
#endif
    }

    /* Create request pool */
