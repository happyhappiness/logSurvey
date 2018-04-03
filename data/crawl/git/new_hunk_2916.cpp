	return lk->fp;
}

int get_lock_file_fd(struct lock_file *lk)
{
	if (!lk->active)
		die("BUG: get_lock_file_fd() called for unlocked object");
	return lk->fd;
}

FILE *get_lock_file_fp(struct lock_file *lk)
{
	if (!lk->active)
		die("BUG: get_lock_file_fp() called for unlocked object");
	return lk->fp;
}

char *get_locked_file_path(struct lock_file *lk)
{
	if (!lk->active)
