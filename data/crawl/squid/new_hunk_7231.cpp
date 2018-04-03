    if (p == NULL)
	return -1;
    /*      fatal_dump("memCopy: NULL mem_node"); *//* Can happen on async */
    assert(size > 0);
    /* Seek our way into store */
    while ((t_off + p->len) < offset) {
	t_off += p->len;
