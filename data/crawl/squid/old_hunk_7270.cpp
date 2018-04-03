    if (!handler)
	fatal_dump("fqdncache_nbgethostbyaddr: NULL handler");

    debug(35, 4, "fqdncache_nbgethostbyaddr: FD %d: Name '%s'.\n", fd, name);
    FqdncacheStats.requests++;

    if (name == NULL || name[0] == '\0') {
	debug(35, 4, "fqdncache_nbgethostbyaddr: Invalid name!\n");
	handler(fd, NULL, handlerData);
	return;
    }
    if ((f = fqdncache_get(name))) {
