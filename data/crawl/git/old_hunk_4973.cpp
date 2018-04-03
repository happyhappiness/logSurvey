		; /* nothing */
}

void close_pack_windows(struct packed_git *p)
{
	while (p->windows) {
