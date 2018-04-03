int finish_async(struct async *async)
{
#ifndef __MINGW32__
	int ret = 0;

	if (wait_or_whine(async->pid))
		ret = error("waitpid (async) failed");
#else
	DWORD ret = 0;
	if (WaitForSingleObject(async->tid, INFINITE) != WAIT_OBJECT_0)