
int finish_async(struct async *async)
{
#ifndef ASYNC_AS_THREAD
	return wait_or_whine(async->pid, "child process", 0);
#else
	void *ret = (void *)(intptr_t)(-1);

	if (pthread_join(async->tid, &ret))
		error("pthread_join failed");
	return (int)(intptr_t)ret;
#endif
}

int run_hook(const char *index_file, const char *name, ...)
