	"Remote Address",
	"Description");
    storeAppendPrintf(sentry, "{---- ------ ---- ---- --------------------- ------------------------------}\n");
    for (i = 0; i < FD_SETSIZE; i++) {
	if (!fdstat_isopen(i))
	    continue;