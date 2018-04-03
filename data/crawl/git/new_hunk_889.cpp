	return hresult;
}

static HANDLE swap_osfhnd(int fd, HANDLE new_handle)
{
	/*
	 * Create a copy of the original handle associated with fd
	 * because the original will get closed when we dup2().
	 */
	HANDLE handle = (HANDLE)_get_osfhandle(fd);
	HANDLE duplicate = duplicate_handle(handle);

	/* Create a temp fd associated with the already open "new_handle". */
	int new_fd = _open_osfhandle((intptr_t)new_handle, O_BINARY);

	assert((fd == 1) || (fd == 2));

	/*
	 * Use stock dup2() to re-bind fd to the new handle.  Note that
	 * this will implicitly close(1) and close both fd=1 and the
	 * originally associated handle.  It will open a new fd=1 and
	 * call DuplicateHandle() on the handle associated with new_fd.
	 * It is because of this implicit close() that we created the
	 * copy of the original.
	 *
	 * Note that the OS can recycle HANDLE (numbers) just like it
	 * recycles fd (numbers), so we must update the cached value
	 * of "console".  You can use GetFileType() to see that
	 * handle and _get_osfhandle(fd) may have the same number
	 * value, but they refer to different actual files now.
	 *
	 * Note that dup2() when given target := {0,1,2} will also
	 * call SetStdHandle(), so we don't need to worry about that.
	 */
	dup2(new_fd, fd);
	if (console == handle)
		console = duplicate;
	handle = INVALID_HANDLE_VALUE;

	/* Close the temp fd.  This explicitly closes "new_handle"
	 * (because it has been associated with it).
	 */
	close(new_fd);

	fd_is_interactive[fd] |= FD_SWAPPED;

	return duplicate;
}

#ifdef DETECT_MSYS_TTY
