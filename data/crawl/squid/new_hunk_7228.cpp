void
comm_remove_close_handler(int fd, PF * handler, void *data)
{
    struct close_handler *p;
    struct close_handler *last = NULL;
    /* Find handler in list */
    for (p = fd_table[fd].close_handler; p != NULL; last = p, p = p->next)
	if (p->handler == handler && p->data == data)
	    break;		/* This is our handler */
    assert(p != NULL);
    /* Remove list entry */
    if (last)
	last->next = p->next;