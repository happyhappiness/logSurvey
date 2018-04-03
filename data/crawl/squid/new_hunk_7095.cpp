    int bytes_into_this_packet = 0;
    debug(19, 6) ("memCopy: offset %d: size %d\n", offset, size);
    if (p == NULL)
	return 0;
    assert(size > 0);
    /* Seek our way into store */
    while ((t_off + p->len) < offset) {