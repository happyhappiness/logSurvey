			; /* do nothing */
		if (i == sizeof(buf))
			die("filename too long");
		path_list_insert(buf, rr)->util = name;
	}
	fclose(in);
}

static struct lock_file write_lock;

static int write_rr(struct path_list *rr, int out_fd)
{
	int i;
	for (i = 0; i < rr->nr; i++) {
		const char *path;
		int length;
		if (!rr->items[i].util)
			continue;
		path = rr->items[i].path;
		length = strlen(path) + 1;
		if (write_in_full(out_fd, rr->items[i].util, 40) != 40 ||
		    write_in_full(out_fd, "\t", 1) != 1 ||
