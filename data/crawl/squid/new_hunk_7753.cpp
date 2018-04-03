	mp.allocated);
    storeAppendPrintf(sentry, "{\tbytes used in maintaining the free tree:\t%d}\n",
	mp.treeoverhead);
#endif /* HAVE_EXT_MALLINFO */
#endif /* HAVE_MALLINFO */

    storeAppendPrintf(sentry, "{File descriptor usage for %s:}\n", appname);
    storeAppendPrintf(sentry, "{\tMax number of file desc available:    %4d}\n",
	FD_SETSIZE);
    storeAppendPrintf(sentry, "{\tLargest file desc currently in use:   %4d}\n",
	fdstat_biggest_fd());
    storeAppendPrintf(sentry, "{\tAvailable number of file descriptors: %4d}\n",
	fdstat_are_n_free_fd(0));
    storeAppendPrintf(sentry, "{\tReserved number of file descriptors:  %4d}\n",
	RESERVED_FD);

    {
	int i;
	char *s = NULL;

	storeAppendPrintf(sentry, "{\tActive file descriptors:}\n");

	for (i = 0; i < FD_SETSIZE; i++) {
	    int lft, to;
	    if (!fdstat_isopen(i))
		continue;
	    line[0] = '\0';
	    switch (fdstat_type(i)) {
	    case FD_SOCKET:
		/* the lifetime should be greater than curtime */
		lft = comm_get_fd_lifetime(i);
		to = comm_get_fd_timeout(i);
