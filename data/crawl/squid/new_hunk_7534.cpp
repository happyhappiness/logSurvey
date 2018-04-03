    storeAppendPrintf(sentry, close_bracket);
}

static void
dummy_handler(int u1, char *u2, void *u3)
{
    return;
}

static int
fqdncacheHasPending(fqdncache_entry * f)
{
    struct _fqdn_pending *p = NULL;
    if (f->status != FQDN_PENDING)
