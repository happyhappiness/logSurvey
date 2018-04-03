	"Description");
    storeAppendPrintf(sentry, "{---- ------ ---- ---- --------------------- ------------------------------}\n");
    for (i = 0; i < Squid_MaxFD; i++) {
	if (!fdstat_isopen(i))
	    continue;
	j = fdstatGetType(i);
