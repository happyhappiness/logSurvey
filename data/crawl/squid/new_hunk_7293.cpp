	f = &fd_table[i];
	if (!fdstat_isopen(i))
	    continue;
	storeAppendPrintf(sentry, "{%4d %-6s ",
	    i,
	    fdstatTypeStr[f->type]);
	switch (f->type) {
	case FD_SOCKET:
	    if ((lft = f->lifetime) < 0)
		lft = 0;
