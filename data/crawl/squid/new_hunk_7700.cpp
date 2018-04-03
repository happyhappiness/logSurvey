     int size, number;
     StoreEntry *sentry;
{
    if (number > 0)
	storeAppendPrintf(sentry, "{\t%d = %d}\n", size, number);
}
#endif

static char *host_port_fmt (host, port)
	char *host;
	u_short port;
{
	static char buf[32];
	sprintf (buf, "%s.%d", host, (int) port);
	return buf;
}

static void statFiledescriptors(sentry)
	StoreEntry *sentry;
{
    int i;
    int j;
    char *s = NULL;
    int lft;
    int to;

    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry, "{Active file descriptors:}\n");
    storeAppendPrintf(sentry, "{%-4s %-6s %-4s %-4s %-21s %s}\n",
	"File",
	"Type",
	"Lftm",
	"Tout",
	"Remote Address",
	"Description");
    storeAppendPrintf(sentry, "{---- ------ ---- ---- --------------------- ------------------------------}\n");
    storeAppendPrintf(sentry, "{}\n");
    for (i = 0; i < FD_SETSIZE; i++) {
	if (!fdstat_isopen(i))
	    continue;
	j = fdstatGetType(i);
	storeAppendPrintf(sentry, "{%4d %-6s ",
		i,
		fdstatTypeStr[j]);
	switch (j) {
	case FD_SOCKET:
	    if ((lft = comm_get_fd_lifetime(i)) < 0)
		lft = 0;
	    to = comm_get_fd_timeout(i);
	    if (lft > 0)
		lft = (lft - squid_curtime) / 60;
	    if (to > 0)
		to = (to - squid_curtime) / 60;
	    storeAppendPrintf(sentry, "%4d %4d %-21s %s}\n",
		lft,
		to,
		host_port_fmt(fd_table[i].ipaddr, fd_table[i].remote_port),
		fd_note(i, NULL));
	    break;
	case FD_FILE:
	    storeAppendPrintf(sentry, "%31s %s}\n",
		"",
		(s = diskFileName(i)) ? s : "-");
	    break;
	case FD_PIPE:
	    storeAppendPrintf(sentry, "%31s %s}\n", "", fd_note(i, NULL));
	    break;
	case FD_LOG:
	    storeAppendPrintf(sentry, "%31s %s}\n", "", fd_note(i, NULL));
	    break;
	case FD_UNKNOWN:
	default:
	    storeAppendPrintf(sentry, "%31s %s}\n", "", fd_note(i, NULL));
	    break;
	}
    }
    storeAppendPrintf(sentry, close_bracket);
}


void info_get(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
    char *tod = NULL;
    wordlist *p = NULL;
    float f;
#ifdef HAVE_MALLINFO
    int t;
#endif
