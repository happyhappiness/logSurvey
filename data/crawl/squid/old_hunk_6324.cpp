static void
fqdncacheEnqueue(fqdncache_entry * f)
{
    struct fqdncacheQueueData *new = xcalloc(1, sizeof(struct fqdncacheQueueData));
    new->f = f;
    *fqdncacheQueueTailP = new;
    fqdncacheQueueTailP = &new->next;
}

static void *
