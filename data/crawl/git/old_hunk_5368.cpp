}

#ifdef ASYNC_AS_THREAD
static void *run_thread(void *data)
{
	struct async *async = data;
	intptr_t ret = async->proc(async->proc_in, async->proc_out, async->data);
	return (void *)ret;
}
#endif

int start_async(struct async *async)
