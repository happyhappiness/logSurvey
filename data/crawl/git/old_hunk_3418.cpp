
static void prepare_order(const char *orderfile)
{
	int fd, cnt, pass;
	void *map;
	char *cp, *endp;
	struct stat st;
	size_t sz;

	if (order)
		return;

	fd = open(orderfile, O_RDONLY);
	if (fd < 0)
		return;
	if (fstat(fd, &st)) {
		close(fd);
		return;
	}
	sz = xsize_t(st.st_size);
	map = mmap(NULL, sz, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	if (map == MAP_FAILED)
		return;
	endp = (char *) map + sz;
	for (pass = 0; pass < 2; pass++) {
		cnt = 0;
		cp = map;
