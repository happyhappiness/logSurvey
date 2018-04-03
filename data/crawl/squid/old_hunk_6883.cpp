	fatal_dump("redirectStart: NULL clientHttpRequest");
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    debug(29, 5) ("redirectStart: '%s'\n", http->url);
    if (Config.Program.redirect == NULL) {
	handler(data, NULL);
	return;
    }
    r = xcalloc(1, sizeof(redirectStateData));
    r->orig_url = xstrdup(http->url);
    r->client_addr = conn->log_addr;
    if (conn->ident.ident == NULL || *conn->ident.ident == '\0') {
	r->client_ident = dash_str;
