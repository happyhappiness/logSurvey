    cs->fd = -1;
    cs->swaplog_fd = -1;
    cs->numcollisions = 0;
    cs->membufs.head = cs->membufs.tail = NULL;		/* set when the rebuild completes */
    cs->current_membuf = NULL;
    cs->index.head = NULL;
    cs->index.tail = NULL;

    parse_cachedir_options(sd, NULL, 0);
    /* Enforce maxobjsize being set to something */
    if (sd->max_objsize == -1)
	fatal("COSS requires max-size to be set to something other than -1!\n");
}


