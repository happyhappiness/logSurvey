	free(array);
}

#ifdef THREADED_DELTA_SEARCH

struct thread_params {
	pthread_t thread;
	struct object_entry **list;
	unsigned list_size;
	int window;
	int depth;
	unsigned *processed;
};

static void *threaded_find_deltas(void *arg)
{
	struct thread_params *p = arg;
	if (p->list_size)
		find_deltas(p->list, p->list_size,
			    p->window, p->depth, p->processed);
	return NULL;
}

#define NR_THREADS	8

static void ll_find_deltas(struct object_entry **list, unsigned list_size,
			   int window, int depth, unsigned *processed)
{
	struct thread_params p[NR_THREADS];
	int i, ret;

	for (i = 0; i < NR_THREADS; i++) {
		unsigned sublist_size = list_size / (NR_THREADS - i);
		p[i].list = list;
		p[i].list_size = sublist_size;
		p[i].window = window;
		p[i].depth = depth;
		p[i].processed = processed;
		ret = pthread_create(&p[i].thread, NULL,
				     threaded_find_deltas, &p[i]);
		if (ret)
			die("unable to create thread: %s", strerror(ret));
		list += sublist_size;
		list_size -= sublist_size;
	}

	for (i = 0; i < NR_THREADS; i++) {
		pthread_join(p[i].thread, NULL);
	}
}

#else
#define ll_find_deltas find_deltas
#endif

static void prepare_pack(int window, int depth)
{
	struct object_entry **delta_list;
