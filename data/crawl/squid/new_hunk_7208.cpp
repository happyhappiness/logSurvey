
    if (!name)
	fatal_dump("ipcache_gethostbyname: NULL name");
    debug(14, 3) ("ipcache_gethostbyname: '%s', flags=%x\n", name, flags);
    IpcacheStats.requests++;
    if ((i = ipcache_get(name))) {
	if (ipcacheExpiredEntry(i)) {
