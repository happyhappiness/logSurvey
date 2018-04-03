	fatal_dump("redirectStart: NULL clientHttpRequest");
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    debug(29, 5, "redirectStart: '%s'\n", http->url);
    if (Config.Program.redirect == NULL) {
	handler(data, NULL);
	return;
