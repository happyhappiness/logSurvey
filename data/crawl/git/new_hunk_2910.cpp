	return lk->fp;
}

const char *get_lock_file_path(struct lock_file *lk)
{
	if (!lk->active)
		die("BUG: get_lock_file_path() called for unlocked object");
	return lk->filename.buf;
}

int get_lock_file_fd(struct lock_file *lk)
{
	if (!lk->active)
