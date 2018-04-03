static int lock_file(struct lock_file *lk, const char *path)
{
	int fd;
	sprintf(lk->filename, "%s.lock", path);
	fd = open(lk->filename, O_RDWR | O_CREAT | O_EXCL, 0666);
	if (0 <= fd) {