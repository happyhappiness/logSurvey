		; /* nothing */
}

void unuse_pack(struct pack_window **w_cursor)
{
	struct pack_window *w = *w_cursor;