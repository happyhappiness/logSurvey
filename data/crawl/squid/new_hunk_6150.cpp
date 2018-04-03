    int i;
    fde *f;
    storeAppendPrintf(sentry, "Active file descriptors:\n");
    storeAppendPrintf(sentry, "%-4s %-6s %-4s %-7s* %-7s* %-21s %s\n",
	"File",
	"Type",
	"Tout",
	"Nread",
	"Nwrite",
	"Remote Address",
	"Description");
    storeAppendPrintf(sentry, "---- ------ ---- -------- -------- --------------------- ------------------------------\n");
    for (i = 0; i < Squid_MaxFD; i++) {
	f = &fd_table[i];
	if (!f->flags.open)
	    continue;
	storeAppendPrintf(sentry, "%4d %-6.6s %4d %7d%c %7d%c %-21s %s\n",
	    i,
	    fdTypeStr[f->type],
	    f->timeout_handler ? (int) (f->timeout - squid_curtime) / 60 : 0,
	    f->bytes_read,
	    f->read_handler ? '*' : ' ',
	    f->bytes_written,
	    f->write_handler ? '*' : ' ',
	    fdRemoteAddr(f),
	    f->desc);
    }
