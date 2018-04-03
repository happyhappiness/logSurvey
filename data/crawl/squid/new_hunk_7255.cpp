

void
redirectStart(clientHttpRequest * http, RH * handler, void *data)
{
    ConnStateData *conn = http->conn;
    redirectStateData *r = NULL;
    redirector_t *redirector = NULL;
    if (!http)
	fatal_dump("redirectStart: NULL clientHttpRequest");
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    debug(29, 5, "redirectStart: '%s'\n", http->url);
    if (Config.Program.redirect == NULL) {
	handler(data, NULL);
	return;
    }
    r = xcalloc(1, sizeof(redirectStateData));
    r->orig_url = xstrdup(http->url);
    r->client_addr = conn->log_addr;
    if (conn->ident.ident == NULL || *conn->ident.ident == '\0') {
	r->client_ident = dash_str;
    } else {
	r->client_ident = conn->ident.ident;
    }
    r->method_s = RequestMethodStr[http->request->method];
    r->handler = handler;
    r->data = data;
    if ((redirector = GetFirstAvailable()))
