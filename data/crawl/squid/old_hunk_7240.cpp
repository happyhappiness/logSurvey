    return len;
}

static int
memCopy(const mem_ptr mem, int offset, char *buf, int size)
{
    mem_node p = mem->head;
    int t_off = mem->origin_offset;
    int bytes_to_go = size;
    char *ptr_to_buf = NULL;
    int bytes_from_this_packet = 0;
    int bytes_into_this_packet = 0;

    debug(19, 6, "memCopy: offset %d: size %d\n", offset, size);

    if (p == NULL)
	return -1;
    /*      fatal_dump("memCopy: NULL mem_node"); *//* Can happen on async */

    if (size <= 0)
	return size;

    /* Seek our way into store */
    while ((t_off + p->len) < offset) {
	t_off += p->len;
	if (p->next)
	    p = p->next;
	else {
	    debug(19, 1, "memCopy: Offset: %d is off limit of current object of %d\n", t_off, offset);
	    return 0;
	}
    }

    /* Start copying begining with this block until
     * we're satiated */

    bytes_into_this_packet = offset - t_off;
    bytes_from_this_packet = min(bytes_to_go,
	p->len - bytes_into_this_packet);

    xmemcpy(buf, p->data + bytes_into_this_packet, bytes_from_this_packet);
    bytes_to_go -= bytes_from_this_packet;
    ptr_to_buf = buf + bytes_from_this_packet;
    p = p->next;

    while (p && bytes_to_go > 0) {
	if (bytes_to_go > p->len) {
	    xmemcpy(ptr_to_buf, p->data, p->len);
