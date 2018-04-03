    debug(19, 6, "memCopy: offset %d: size %d\n", offset, size);

    if (p == NULL)
	fatal_dump("memCopy: NULL mem_node");

    if (size <= 0)
	return size;
