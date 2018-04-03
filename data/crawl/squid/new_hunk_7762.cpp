    mem_node p = mem->head;
    int t_off = mem->origin_offset;
    int bytes_to_go = size;
    char *ptr_to_buf = NULL;
    int bytes_from_this_packet = 0;
    int bytes_into_this_packet = 0;

    debug(19, 6, "memCopy: offset %d: size %d\n", offset, size);

    if (p == NULL)
	fatal_dump("memCopy: NULL mem_node");

    if (size <= 0)
	return size;

