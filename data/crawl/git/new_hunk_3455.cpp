		*alternate_shallow_file = "";
	strbuf_release(&sb);
}

static int advertise_shallow_grafts_cb(const struct commit_graft *graft, void *cb)
{
	int fd = *(int *)cb;
	if (graft->nr_parent == -1)
		packet_write(fd, "shallow %s\n", sha1_to_hex(graft->sha1));
	return 0;
}

void advertise_shallow_grafts(int fd)
{
	if (!is_repository_shallow())
		return;
	for_each_commit_graft(advertise_shallow_grafts_cb, &fd);
}
