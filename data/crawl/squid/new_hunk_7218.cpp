    char *ptr_to_buf = NULL;
    int bytes_from_this_packet = 0;
    int bytes_into_this_packet = 0;
    debug(19, 6) ("memCopy: offset %d: size %d\n", offset, size);
    if (p == NULL)
	return -1;
    /*      fatal_dump("memCopy: NULL mem_node"); *//* Can happen on async */
