	f = &fd_table[i];
	if (!fdstat_isopen(i))
	    continue;
	j = fdstatGetType(i);
	storeAppendPrintf(sentry, "{%4d %-6s ",
	    i,
	    fdstatTypeStr[j]);
	switch (j) {
	case FD_SOCKET:
	    if ((lft = f->lifetime) < 0)
		lft = 0;
