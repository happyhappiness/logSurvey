

void
redirectStart(int cfd, icpStateData * icpState, RH * handler, void *data)
{
    redirectStateData *r = NULL;
    redirector_t *redirector = NULL;
    debug(29, 5, "redirectStart: '%s'\n", icpState->url);
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    if (!icpState)
	fatal_dump("redirectStart: NULL icpState");
    if (Config.Program.redirect == NULL) {
	handler(data, NULL);
	return;
    }
    r = xcalloc(1, sizeof(redirectStateData));
    r->fd = cfd;
    r->orig_url = xstrdup(icpState->url);
    r->client_addr = icpState->log_addr;
    if (icpState->ident.ident == NULL || *icpState->ident.ident == '\0') {
	r->client_ident = dash_str;
    } else {
	r->client_ident = icpState->ident.ident;
    }
    r->method_s = RequestMethodStr[icpState->request->method];
    r->handler = handler;
    r->data = data;
    if ((redirector = GetFirstAvailable()))
