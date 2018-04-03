    for (i = 0; i < 20; i++) {
	t = create_a_thing(argv);
	assert(t);
	if (debug)
	    fprintf(stderr, "Thing #%d on FD %d/%d\n",
		i, t->rfd, t->wfd);
	*T = t;
	T = &t->next;
    }
