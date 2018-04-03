	return 0;
}

int poll(struct pollfd *ufds, unsigned int nfds, int timeout)
{
	int i, pending;

	if (timeout >= 0) {
		if (nfds == 0) {
			Sleep(timeout);
			return 0;
		}
		return errno = EINVAL, error("poll timeout not supported");
	}

	/* When there is only one fd to wait for, then we pretend that
	 * input is available and let the actual wait happen when the
	 * caller invokes read().
	 */
	if (nfds == 1) {
		if (!(ufds[0].events & POLLIN))
			return errno = EINVAL, error("POLLIN not set");
		ufds[0].revents = POLLIN;
		return 0;
	}

repeat:
	pending = 0;
	for (i = 0; i < nfds; i++) {
		DWORD avail = 0;
		HANDLE h = (HANDLE) _get_osfhandle(ufds[i].fd);
		if (h == INVALID_HANDLE_VALUE)
			return -1;	/* errno was set */

		if (!(ufds[i].events & POLLIN))
			return errno = EINVAL, error("POLLIN not set");

		/* this emulation works only for pipes */
		if (!PeekNamedPipe(h, NULL, 0, NULL, &avail, NULL)) {
			int err = GetLastError();
			if (err == ERROR_BROKEN_PIPE) {
				ufds[i].revents = POLLHUP;
				pending++;
			} else {
				errno = EINVAL;
				return error("PeekNamedPipe failed,"
					" GetLastError: %u", err);
			}
		} else if (avail) {
			ufds[i].revents = POLLIN;
			pending++;
		} else
			ufds[i].revents = 0;
	}
	if (!pending) {
		/* The only times that we spin here is when the process
		 * that is connected through the pipes is waiting for
		 * its own input data to become available. But since
		 * the process (pack-objects) is itself CPU intensive,
		 * it will happily pick up the time slice that we are
		 * relinquishing here.
		 */
		Sleep(0);
		goto repeat;
	}
	return 0;
}

struct tm *gmtime_r(const time_t *timep, struct tm *result)
{
	/* gmtime() in MSVCRT.DLL is thread-safe, but not reentrant */