
int finish_async(struct async *async)
{
#ifndef WIN32
	int ret = wait_or_whine(async->pid, "child process", 0);
#else
	DWORD ret = 0;
	if (WaitForSingleObject(async->tid, INFINITE) != WAIT_OBJECT_0)
		ret = error("waiting for thread failed: %lu", GetLastError());
	else if (!GetExitCodeThread(async->tid, &ret))
		ret = error("cannot get thread exit code: %lu", GetLastError());
	CloseHandle(async->tid);
#endif
	return ret;
}

int run_hook(const char *index_file, const char *name, ...)
