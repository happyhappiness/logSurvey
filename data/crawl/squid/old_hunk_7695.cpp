    if ((t = strchr(redirector->inbuf, '\n'))) {
	/* end of record found */
	*t = '\0';
	if (t == redirector->inbuf)
	    r->handler(r->fd, r->orig_url);
	else
	    r->handler(r->fd, redirector->inbuf);
	redirector->redirectState = NULL;
	redirector->flags &= ~REDIRECT_FLAG_BUSY;
    }
    while ((r = Dequeue()) && (redirector = GetFirstAvailable()))
	redirectDispatch(redirector, r);
    return 0;
}

void redirectStart(url, fd, handler)
     char *url;
     int fd;
     RH handler;
{
    redirectStateData *r = NULL;
    redirector_t *redirector = NULL;

    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    r = xcalloc(1, sizeof(redirectStateData));
    r->fd = fd;
    r->orig_url = url;
    r->handler = handler;
    if ((redirector = GetFirstAvailable()))
	redirectDispatch(redirector, r);
    else
	Enqueue(r);
}

static void Enqueue(r)
     redirectStateData *r;
{
    struct redirectQueueData *new = xcalloc(1, sizeof(struct redirectQueueData));
    new->redirectState = r;
    *redirectQueueTailP = new;
    redirectQueueTailP = &new->next;
}

static redirectStateData *Dequeue()
