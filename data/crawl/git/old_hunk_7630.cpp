
#ifdef THREADED_DELTA_SEARCH

struct thread_params {
	pthread_t thread;
	struct object_entry **list;
	unsigned list_size;
	unsigned remaining;
	int window;
	int depth;
	unsigned *processed;
};

static pthread_mutex_t data_request  = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t data_ready    = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t data_provider = PTHREAD_MUTEX_INITIALIZER;
static struct thread_params *data_requester;

static void *threaded_find_deltas(void *arg)
{
	struct thread_params *me = arg;

	for (;;) {
		pthread_mutex_lock(&data_request);
		data_requester = me;
		pthread_mutex_unlock(&data_provider);
		pthread_mutex_lock(&data_ready);
		pthread_mutex_unlock(&data_request);

		if (!me->remaining)
			return NULL;

		find_deltas(me->list, &me->remaining,
			    me->window, me->depth, me->processed);
	}
}

static void ll_find_deltas(struct object_entry **list, unsigned list_size,
			   int window, int depth, unsigned *processed)
{
	struct thread_params *target, p[delta_search_threads];
	int i, ret, active_threads = 0;

	if (delta_search_threads <= 1) {
		find_deltas(list, &list_size, window, depth, processed);
		return;
	}

	pthread_mutex_lock(&data_provider);
	pthread_mutex_lock(&data_ready);

	/* Start work threads. */
	for (i = 0; i < delta_search_threads; i++) {
		p[i].window = window;
		p[i].depth = depth;
		p[i].processed = processed;
		p[i].remaining = 0;
		ret = pthread_create(&p[i].thread, NULL,
				     threaded_find_deltas, &p[i]);
		if (ret)
			die("unable to create thread: %s", strerror(ret));
		active_threads++;
	}

	/* Then partition the work amongst them. */
	for (i = 0; i < delta_search_threads; i++) {
		unsigned sub_size = list_size / (delta_search_threads - i);

		pthread_mutex_lock(&data_provider);
		target = data_requester;
		if (!sub_size) {
			pthread_mutex_unlock(&data_ready);
			pthread_join(target->thread, NULL);
			active_threads--;
			continue;
		}

		/* try to split chunks on "path" boundaries */
		while (sub_size < list_size && list[sub_size]->hash &&
		       list[sub_size]->hash == list[sub_size-1]->hash)
			sub_size++;

		target->list = list;
		target->list_size = sub_size;
		target->remaining = sub_size;
		pthread_mutex_unlock(&data_ready);

		list += sub_size;
		list_size -= sub_size;
	}

	/*
	 * Now let's wait for work completion.  Each time a thread is done
	 * with its work, we steal half of the remaining work from the
