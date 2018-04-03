{
    int i;
    fde *f;
    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry, "{Active file descriptors:}\n");
    storeAppendPrintf(sentry, "{%-4s %-6s %-4s %-7s %-7s %-21s %s}\n",
	"File",
	"Type",
	"Tout",
	"Nread",
	"Nwrite",
	"Remote Address",
	"Description");
    storeAppendPrintf(sentry, "{---- ------ ---- ------- ------- --------------------- ------------------------------}\n");
    for (i = 0; i < Squid_MaxFD; i++) {
	f = &fd_table[i];
	if (!f->open)
	    continue;
	storeAppendPrintf(sentry, "{%4d %-6.6s %4d %7d %7d %-21s %s}\n",
	    i,
	    fdstatTypeStr[f->type],
	    f->timeout_handler ? (f->timeout - squid_curtime) / 60 : 0,
