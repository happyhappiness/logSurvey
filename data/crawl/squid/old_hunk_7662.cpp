/**** PUBLIC FUNCTIONS ****/


void redirectStart(url, fd, handler, data)
     char *url;
     int fd;
     RH handler;
     void *data;
{
    redirectStateData *r = NULL;
    redirector_t *redirector = NULL;
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    if (Config.Program.redirect == NULL) {
	(*handler) (data, NULL);
	return;
    }
    r = xcalloc(1, sizeof(redirectStateData));
    r->fd = fd;
    r->orig_url = url;
    r->handler = handler;
    r->data = data;
    if ((redirector = GetFirstAvailable()))