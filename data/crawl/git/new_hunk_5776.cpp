int finish_async(struct async *async)
{
#ifndef __MINGW32__
	int ret = wait_or_whine(async->pid, "child process");
#else
	DWORD ret = 0;
	if (WaitForSingleObject(async->tid, INFINITE) != WAIT_OBJECT_0)
