	return 0;
}

static int do_plain_rerere(struct path_list *rr, int fd)
{
	struct path_list conflict = { NULL, 0, 0, 1 };
