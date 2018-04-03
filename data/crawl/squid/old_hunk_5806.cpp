    cs->fd = -1;
    cs->swaplog_fd = -1;
    cs->numcollisions = 0;
    cs->membufs = NULL;		/* set when the rebuild completes */
    cs->current_membuf = cs->membufs;
    cs->index.head = NULL;
    cs->index.tail = NULL;

    parse_cachedir_options(sd, NULL, 0);
}


