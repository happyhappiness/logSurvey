    if (srv->wqueue->isNull())
        srv->wqueue->init();

    if (hlp->concurrency)
        srv->wqueue->Printf("%d %s", slot, r->buf);
    else
        srv->wqueue->append(r->buf, strlen(r->buf));