	munmap(map, mapsz);
}

void add_to_alternates_file(const char *reference)
{
	struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
	int fd = hold_lock_file_for_append(lock, git_path("objects/info/alternates"), 1);
	char *alt = mkpath("%s/objects\n", reference);
	write_or_die(fd, alt, strlen(alt));
	if (commit_lock_file(lock))
		die("could not close alternates file");
	if (alt_odb_tail)
		link_alt_odb_entries(alt, alt + strlen(alt), '\n', NULL, 0);
}

void prepare_alt_odb(void)
{
	const char *alt;