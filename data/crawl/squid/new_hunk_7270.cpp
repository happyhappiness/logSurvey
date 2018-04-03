    if (!handler)
	fatal_dump("fqdncache_nbgethostbyaddr: NULL handler");

    debug(35, 4, "fqdncache_nbgethostbyaddr: Name '%s'.\n", name);
    FqdncacheStats.requests++;

    if (name == NULL || name[0] == '\0') {
	debug(35, 4, "fqdncache_nbgethostbyaddr: Invalid name!\n");
	handler(NULL, handlerData);
	return;
    }
    if ((f = fqdncache_get(name))) {
